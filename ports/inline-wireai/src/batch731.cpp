// batch731.cpp - soldier AI, batch 731 (2026-10-12): CActorActionMarker::Update() (0x5eac90) [medium].
// Pass 1, every record: if its flag byte is set, time -= the engine frame step (0x70039c+0x48). The record's object gives
// X = obj->slot 0x20(); if X->+8 has flag 0x800 the record is skipped. Otherwise obj->slot 0x3a0(B, A) returns r1, obj->slot
// 0x390(r1) is called, A.y += 54, obj->slot 0x84(A), and ZOnScreenDisplay::ActionMarkerAdd(A, record type, 1.0, -1) runs on the
// display stored at the marker's first dword.
// Pass 2: records with a negative time are updated: a non-zero a replaces the type and the time becomes the dword b
// (reinterpreted as float). Otherwise a record of type 8 is kept and any other is removed by moving the last record into its
// slot and dropping the count (the moved record is not revisited). Non-negative times and NaN are kept.
#include "ff.h"

struct MarkerRec {
  u32 obj;      // +0
  u32 type;     // +4
  float time;   // +8
  u32 a;        // +0xc
  u32 b;        // +0x10
  u8 flag;      // +0x14
};

extern "C" void THISCALL ext_5a57a0(void *osd, float *A, u32 type, float one, s32 minusOne);   // ZOnScreenDisplay::ActionMarkerAdd

// 0x5eac90 CActorActionMarker::Update() [medium].
static void THISCALL marker_Update(u8 *self) {
  MarkerRec **arr = (MarkerRec **)(self + 4);
  float A[3], B[3];

  for (u32 i = 0; i < *(u32 *)(self + 0x44); i++) {
    MarkerRec *r = arr[i];
    if (r->flag) {
      float dt = *(float *)((u8 *)*(void **)0x70039c + 0x48);
      r->time = r->time - dt;
    }
    void *obj = (void *)r->obj;
    void *X = vcall<void *>(obj, 0x20);
    u8 *Y = *(u8 **)((u8 *)X + 8);
    if (*(u32 *)(Y + 0x3c) & 0x800)
      continue;
    u32 r1 = vcall<u32>(obj, 0x3a0, B, A);
    vcall<void>(obj, 0x390, r1);
    A[1] = A[1] + bitsf(0x42580000u);      // 54
    vcall<void>(obj, 0x84, A);
    ext_5a57a0(*(void **)self, A, arr[i]->type, bitsf(0x3f800000u), -1);
  }

  u32 i = 0;
  while (i < *(u32 *)(self + 0x44)) {
    MarkerRec *r = arr[i];
    if (!(r->time < 0.0f)) {
      i++;
      continue;
    }
    if (r->a != 0) {
      r->type = r->a;
      r->time = *(float *)&r->b;
      i++;
      continue;
    }
    if (r->type == 8) {
      i++;
      continue;
    }
    u32 cnt = *(u32 *)(self + 0x44);
    if (i != cnt - 1) {
      MarkerRec *last = arr[cnt - 1];
      for (int k = 0; k < 16; k++)
        ((u8 *)r)[k] = ((u8 *)last)[k];
      r->b = last->b;
      r->flag = last->flag;
    }
    *(u32 *)(self + 0x44) = cnt - 1;
    i++;
  }
}
PCREG(5eac90, marker_Update);
