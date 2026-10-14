// batch33013.cpp - cascade h3 tier B: four thunks with wrapper logic
#include "ff.h"

extern "C" void THISCALL ext_4db1f0(u8 *self);
extern "C" void THISCALL ext_4db6c0(u8 *self);

// 0x45edd0: load ecx[8], then tail jump
static void THISCALL fn45edd0(u8 *self) {
  u8 *ptr = *(u8 **)(self + 8);
  ext_4db1f0(ptr);
}
PCREG(45edd0, fn45edd0);

// 0x45f050: load ecx[8], then tail jump
static void THISCALL fn45f050(u8 *self) {
  u8 *ptr = *(u8 **)(self + 8);
  ext_4db6c0(ptr);
}
PCREG(45f050, fn45f050);

// 0x45faf0: read ecx[0], then tail jump through vtable at +0x128
static void THISCALL fn45faf0(u8 *self) {
  u8 *vt = *(u8 **)self;
  typedef void(THISCALL *vfn_t)(void *);
  (*(vfn_t *)(vt + 0x128))(self);
}
PCREG(45faf0, fn45faf0);

// 0x463930: read ecx[0], then tail jump through vtable at +0x7c
static void THISCALL fn463930(u8 *self) {
  u8 *vt = *(u8 **)self;
  typedef void(THISCALL *vfn_t)(void *);
  (*(vfn_t *)(vt + 0x7c))(self);
}
PCREG(463930, fn463930);
