// batch706.cpp - soldier AI, batch 706 (2026-10-11): CCheckVisible::FrameUpdate, the per-frame sight test.
//
// Summary (all from 0x4a9fe0; constants with their exe addresses):
//  * Works through the seer table round-robin from cursor +0x15e58 and, inside a seer, through the objects from cursor
//    +0x15e54, so a frame can stop anywhere and resume next frame. Per frame at most 20 used seers are started and at
//    most 5 line-of-sight tests are made. When the seer cursor wraps, the time since the previous wrap (static
//    0x700330) is checked: more than 2 s (0x800 ticks) logs "Warning: CheckVisible update took %f seconds. Sight might
//    suffer.." (the original passes an int for %f).
//  * Each pair keeps a countdown in 60 Hz frames (state low 14 bits). A seer's elapsed frames since its last full pass
//    (+0x20 time, +0x24 fraction) are subtracted; pairs still counting down are skipped.
//  * A seer or object is inactive when bit 10 of geom->[+8]->[+0x3c] is set, or, for ZActors, when CheckSight()
//    (slot 0x690) is false. Inactive seers get flag 4 (all their pairs re-checked next time); inactive objects lose
//    sight and wait 60 frames.
//  * Range = distance multiplier (+0x15e78) * seer range (+4), halved when the seer is an IK character and
//    ReducedSight(object) (slot 0x444) is true. Distance is capped at 10000. Out of range: lose sight, wait
//    ((d - range) * 0.0005 + 1) * 60 frames.
//  * Closer than 200 and not sneaking: no field-of-view test. Otherwise the target must be inside the seer's cone
//    (dot(eye dir, to-target dir) >= cos(half fov) at +8), else lose sight and re-check next frame.
//  * Line of sight: COLI ray from the eye along the eye->target vector, collision slot 0x2e0(coli, 0, 0x10, -1, 1, 1).
//    Blocked: lose sight, wait (d < 1000 ? d * 0.0005 : 1) * 60 frames. Clear: UpdateVisible(seer, obj, seen, no
//    resend) and wait 60 frames.
//  * With m_fShowCheck (0x700328) non-zero, debug lines are drawn for each result (yellow 0xffffff00 = out of range
//    only because of ReducedSight, red 0xffff0000 = outside the cone or blocked, green 0xff00ff00 = seen) and the
//    previous frame's lines (list at +0x15e5c) are removed first.
//  * Engine profiling (when engine +0x9c7 and +0x9c3 are both non-zero): slot 0x1c8 timer, 0x178/0x17c begin/end
//    "Visible".
// Engine (0x70039c): +0x40 tick (1/1024 s), +0x9b geom database (slot 0x58 ref->geom; +0xadc the scene/collision
// object: slot 0x218 add debug line, 0x220 remove it, 0x2e0 ray test).
#include "ff.h"

extern "C" void THISCALL ext_4aabe0(void *, float *, float *, void *, const void *, u32);   // GetSeerPosDir
extern "C" void THISCALL ext_4aaa50(void *, float *, u8 *, void *, u32);                   // GetObjectPosSneak
extern "C" void THISCALL ext_4ab920(void *, u32, u32, u32, u32);                           // UpdateVisible
extern "C" void THISCALL ext_4ab8e0(u16 *, s32);                                           // state timer setter
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);            // out = a - b (x87)
extern "C" float FASTCALL ext_44e630(float *out, const float *v);                           // vnorm, returns length
extern "C" void *THISCALL ext_4e1b60(void *);                                               // COLI::COLI
extern "C" void *memset_634d10(void *, int, u32) asm("ext_634d10");

struct COLI { float start[3]; float delta[3]; u8 rest[0x58]; };

static inline u8 *engine() { return *(u8 **)0x70039c; }
static inline void *scene() { return *(void **)(*(u8 **)(engine() + 0x9b) + 0xadc); }

static void cv_lose(u8 *self, u32 seer, u32 obj) {
  u8 *s = self + 0x694 + seer * 0x1b8;
  u16 *st = (u16 *)(s + 0x28) + obj;
  u16 v = *st;
  if (v >> 14 & 1) {
    *st = v & 0xbfff;
    vcall<void>(*(void **)(self + 0x44), 0x12c, *(u32 *)s, (u32) * (u16 *)(self + 0x52), *(u32 *)(self + 0x54 + obj * 8));
  }
}

static void cv_draw(u8 *self, float *from, float *to, u32 color) {
  void *list = self + 0x15e5c;
  void *sc = scene();
  u32 h = vcall<u32>(sc, 0x218, from, to, color);
  vcall<void>(list, 4, h);
}

static void cv_assert() {
  void (*h)() = *(void (**)())0x7003b0;
  if (h)
    h();
  else
    __builtin_debugtrap();
}

static inline void cv_set_timer(u16 *st, s32 t) {
  if (t < 0 || t > 0x3fff)
    cv_assert();
  *st ^= (u16)((*st ^ (u16)t) & 0x3fff);
}

static inline bool show_check() { return !(G(float, 0x700328) == 0.0f); }

static void THISCALL cv_FrameUpdate(u8 *self) {
  float objPos[200][3];
  u8 objActive[200];
  u8 objSneak[200];
  u8 objDone[200];
  float eyePos[3], eyeDir[3], diff[3], dir[3];
  u32 iter[3];
  u32 tmpTime;

  u8 *eng = engine();
  if (!(*(float *)(eng + 0x9c7) == 0.0f) && !(*(float *)(eng + 0x9c3) == 0.0f)) {
    u64 t = vcall<u64>(eng, 0x1c8, (const char *)0x67a7f8, 0x259);
    vcall<void>(*(void **)0x70039c, 0x178, t, (const char *)0x690934);
  }
  void *list = self + 0x15e5c;
  vcall<void>(list, 0x4c, iter);
  u32 e = vcall<u32>(list, 0x5c, iter);
  while (iter[0] != 0) {
    vcall<void>(scene(), 0x220, e);
    e = vcall<u32>(list, 0x5c, iter);
  }
  vcall<void>(list, 0xc);

  s32 now = *(s32 *)(engine() + 0x40);
  s32 losBudget = 5;
  s32 seerBudget = 20;
  memset_634d10(objDone, 0, 200);
  u32 &seerCur = *(u32 *)(self + 0x15e58);
  u32 &objCur = *(u32 *)(self + 0x15e54);
  for (u32 count = 0;; count++) {
    if (seerCur == 200) {
      if (now - G(s32, 0x700330) > 0x800) {
        void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x690610, 0x2df);
        float f = (float)now * 0.0009765625f * -1024.0f;
        s32 took = -G(s32, 0x700330) - _mm_cvttss_si32(_mm_set_ss(f));
        typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, s32);
        (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x690940, took);
      }
      G(s32, 0x700330) = now;
      seerCur = 0;
    }
    if (count == 200)
      break;
    u8 *seer = self + 0x694 + seerCur * 0x1b8;
    u32 seerRef = *(u32 *)seer;
    if (seerRef != 0) {
      if (seerBudget-- == 0)
        break;
      void *db = *(void **)(engine() + 0x9b);
      u8 *sg = vcall<u8 *>(db, 0x58, seerRef);
      ext_4aabe0(self, eyePos, eyeDir, sg, seer + 0x10, *(u8 *)(seer + 0x1c) & 1);
      bool active = !((*(u32 *)(*(u8 **)(sg + 8) + 0x3c) >> 10) & 1);
      if (*(u8 *)(seer + 0x1c) & 2) {
        if (!vcall<bool>(sg, 0x690))
          active = false;
      }
      if (!active) {
        *(u32 *)(seer + 0x1c) |= 4;
        goto next_seer;
      }
      {
        float el = (float)(now - *(s32 *)(seer + 0x20)) * 0.0009765625f * 60.0f;
        s32 n = _mm_cvttss_si32(_mm_set_ss(el));
        float fr = el - (float)n + *(float *)(seer + 0x24);
        *(float *)(seer + 0x24) = fr;
        if (fr > 1.0f) {
          *(float *)(seer + 0x24) = fr - 1.0f;
          n++;
        }
        if (n == 0)
          goto next_seer;
        if (n > 0x3fff)
          n = 0x3fff;
        if (objCur != 200) {
          do {
            u32 i = objCur;
            u16 *st = (u16 *)(seer + 0x28) + i;
            u16 w = *st;
            if (w >> 15 & 1) {
              s32 left = (s32)(w & 0x3fff) - n;
              if (!(*(u8 *)(seer + 0x1c) & 4) && left > 0) {
                cv_set_timer(st, left);
                goto next_obj;
              }
              if (!objDone[i]) {
                objDone[i] = 1;
                db = *(void **)(engine() + 0x9b);
                u8 *og = vcall<u8 *>(db, 0x58, *(u32 *)(self + 0x54 + i * 8));
                objActive[i] = !((*(u32 *)(*(u8 **)(og + 8) + 0x3c) >> 10) & 1);
                if (objActive[i] && (*(u8 *)(self + 0x58 + i * 8) & 2) && !vcall<bool>(og, 0x690))
                  objActive[i] = 0;
                if (objActive[i])
                  ext_4aaa50(self, objPos[i], &objSneak[i], og, *(u8 *)(self + 0x58 + i * 8) & 1);
              }
              if (!objActive[i]) {
                cv_lose(self, seerCur, i);
                *st = (*st & 0xc03c) | 0x3c;
                goto next_obj;
              }
              float mult = 1.0f;
              if ((*(u8 *)(seer + 0x1c) & 1) && vcall<bool>(sg, 0x444, *(u32 *)(self + 0x54 + i * 8)))
                mult = 0.5f;                                   // 0x67a6ac
              ext_43e920(diff, objPos[i], eyePos);
              float dist = ext_44e630(dir, diff);
              float range = *(float *)(self + 0x15e78) * *(float *)(seer + 4) * mult;
              float d = (10000.0f < dist) ? 10000.0f : dist;   // 0x67ff1c, minss
              if (d > range) {
                if (show_check() && range / mult > d)
                  cv_draw(self, objPos[i], eyePos, 0xffffff00);
                cv_lose(self, seerCur, i);
                s32 t = _mm_cvttss_si32(_mm_set_ss(((d - range) * 0.0005f + 1.0f) * 60.0f));
                cv_set_timer(st, t);
                goto next_obj;
              }
              if (!(200.0f > d) || objSneak[i]) {
                float dot = eyeDir[1] * dir[1] + eyeDir[0] * dir[0];
                dot = dot + eyeDir[2] * dir[2];
                if (*(float *)(seer + 8) > dot) {
                  if (show_check())
                    cv_draw(self, objPos[i], eyePos, 0xffff0000);
                  cv_lose(self, seerCur, i);
                  *st &= 0xc000;
                  goto next_obj;
                }
              }
              {
                COLI c;
                ext_4e1b60(&c);
                c.start[0] = eyePos[0];
                c.start[1] = eyePos[1];
                c.start[2] = eyePos[2];
                c.delta[0] = diff[0];
                c.delta[1] = diff[1];
                c.delta[2] = diff[2];
                bool hit = vcall<bool>(scene(), 0x2e0, &c, 0, 0x10, -1, 1, 1);
                if (hit) {
                  if (show_check())
                    cv_draw(self, objPos[i], eyePos, 0xffff0000);
                  cv_lose(self, seerCur, i);
                  float k = (1000.0f > d) ? d * 0.0005f : 1.0f;  // 0x67d164
                  ext_4ab8e0(st, _mm_cvttss_si32(_mm_set_ss(k * 60.0f)));
                } else {
                  if (show_check())
                    cv_draw(self, objPos[i], eyePos, 0xff00ff00);
                  ext_4ab920(self, seerCur, objCur, 1, 0);
                  *st = (*st & 0xc03c) | 0x3c;
                }
                if (--losBudget == 0)
                  goto done;
              }
            }
          next_obj:
            objCur++;
          } while (objCur != 200);
        }
        objCur = 0;
        if (losBudget == 0)
          goto done;
        *(u32 *)(seer + 0x1c) &= ~4u;
        if ((u32 *)(seer + 0x20) != &tmpTime)
          *(s32 *)(seer + 0x20) = now;
      }
    }
  next_seer:
    seerCur++;
  }
done:
  eng = engine();
  if (!(*(float *)(eng + 0x9c7) == 0.0f) && !(*(float *)(eng + 0x9c3) == 0.0f)) {
    u64 t = vcall<u64>(eng, 0x1c8, (const char *)0x67a7f8, 0x260);
    vcall<void>(*(void **)0x70039c, 0x17c, t, (const char *)0x690934);
  }
}
PCREG(4a9fe0, cv_FrameUpdate);
