// batch759.cpp - area 72, call-then-jump rows with zero-argument callees (2026-10-12). See docs/20-unclaimed-72.md.
#include "ff.h"

extern "C" void THISCALL ext_5aef10(void *self);       // zero-argument base call
extern "C" u32 THISCALL ext_566f10(void *self);        // CController::GetCS (returns eax)
extern "C" void THISCALL ext_562440(void *self);       // CBaseWindow::Init (zero args)
extern "C" void THISCALL ext_56a140(void *self);       // CLinkMenu::LoadInit (zero args, tail target)
extern "C" void THISCALL ext_564b10(void *self);       // CFileWindow::Init (zero args)
extern "C" void THISCALL ext_56bd90(void *self);       // CLoadMenu::LoadInit (zero args, tail target)
extern "C" void THISCALL ext_57f420(void *self);       // tail target of 0x57f400

static u8 *THISCALL f_5aeda0(u8 *self) { ext_5aef10(self); return self; }
PCREG(5aeda0, f_5aeda0);

static void THISCALL f_566e40(u8 *self) { *(u32 *)(self + 0x198) = ext_566f10(self); }
PCREG(566e40, f_566e40);

static void THISCALL f_56a080(u8 *self) { ext_562440(self); ext_56a140(self); }
PCREG(56a080, f_56a080);

static void THISCALL f_56ba00(u8 *self) { ext_564b10(self); ext_56bd90(self); }
PCREG(56ba00, f_56ba00);

static void THISCALL f_57f400(u8 *self) { ext_562440(self); ext_57f420(self); }
PCREG(57f400, f_57f400);
