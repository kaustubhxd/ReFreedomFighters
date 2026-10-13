// batch1054.cpp - unclaimed-04 batch 54 (docs/20-unclaimed-04.md): 0x6552f0 (residue 3).
// thiscall (al), ret 4. GUESS: some kind of setter with Windows API calls.
#include "ff.h"

// Define function pointer types for the Windows API calls
typedef int(__attribute__((stdcall)) *GetClientRect_t)(void *hwnd, void *lpRect);
typedef int(__attribute__((stdcall)) *ClientToScreen_t)(void *hwnd, void *lppt);
typedef int(__attribute__((stdcall)) *ClipCursor_t)(const void *lpRect);

// Create function pointers at the IAT addresses
#define GET_CLIENT_RECT (*(GetClientRect_t *)0x676210)
#define CLIENT_TO_SCREEN (*(ClientToScreen_t *)0x676238)
#define CLIP_CURSOR (*(ClipCursor_t *)0x676230)

// 0x6552f0. Thiscall, one byte argument, ret 4.
static void THISCALL unk6552f0(u8 *self, u8 al) {
  self[0x11e7] = al;

  if (al != 0) {
    u8 buf1[0x14] = {0};
    u8 buf2[0x0c] = {0};

    // Get the dword value at this+0x133
    u32 param = *(u32 *)(self + 0x133);

    // Call GetClientRect with param and local buffer
    GET_CLIENT_RECT((void *)param, (void *)buf1);

    // Call ClientToScreen with param and same buffer
    CLIENT_TO_SCREEN((void *)param, (void *)buf1);

    // Call ClientToScreen again with different buffer
    CLIENT_TO_SCREEN((void *)param, (void *)buf2);

    // Call ClipCursor with first buffer
    CLIP_CURSOR((const void *)buf1);
  } else {
    // Call ClipCursor with NULL
    CLIP_CURSOR((const void *)0);
  }
}

PCREG(6552f0, unk6552f0);
