"""specs_s309.py - unclaimed-43 batch 309: ZPlayer::ForceLHandItem(ZItem *item, bool flag) (0x483660), thiscall, ret 8.
Mocks (logging vtables, values drawn in gen):
  - this: slot 0x514 returns r (0, 1 or 2); slots 0x45c (two args) and 0x524 (one arg) log their arguments;
  - the engine (g_pSysInterface at 0x70039c, member +0x9b): slot 0x4c returns a value that the caller passes to 0x524;
  - the item: slot 0x2d0 (two args) logs its arguments.
flag is passed as a dword whose low byte is the bool: 0, 1 and 0x100 (low byte 0) are all used."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

NSLOTS_SELF = 0x528 // 4      # slots up to 0x524
NSLOTS_EN = 0x50 // 4         # slot 0x4c
NSLOTS_ITEM = 0x2d4 // 4      # slot 0x2d0


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vtable(c, name, nslots, impl, argwords, cdecl=()):
    slots = {}
    for i in range(nslots):
        off = 4 * i

        def h(e, r, off=off):
            n = argwords.get(off, 0)
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            f = impl.get(off)
            eax, st0 = (f(e, args) if f else (0, None))
            e.ret(eax=eax, argbytes=0 if off in cdecl else 4 * n, st0=st0)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _gen(c):
    r = c.rng
    rv = r.choice([0, 1, 2])
    back = r.getrandbits(32)
    self_ = E.zero_obj(c, 0x40)
    selfvt = _vtable(c, 'ZPLAYERHAND', NSLOTS_SELF, {0x514: lambda e, a: (rv, None)},
                     {0x45c: 2, 0x524: 1, 0x514: 0})
    c.emu.w32(self_, selfvt)

    en = E.zero_obj(c, 0x40)
    envt = _vtable(c, 'ZPLAYERENGINE', NSLOTS_EN, {0x4c: lambda e, a: (back, None)}, {0x4c: 1})
    c.emu.w32(en, envt)
    eng = E.zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    E.set_global(c, 0x70039c, eng)

    item = 0 if r.random() < 0.15 else E.zero_obj(c, 0x40)
    if item:
        itvt = _vtable(c, 'ZITEM', NSLOTS_ITEM, {}, {0x2d0: 2})
        c.emu.w32(item, itvt)
    flag = r.choice([0, 0, 1, 0x100, 0x101])
    c.emu.mu.ctl_flush_tb()
    return [self_, item, flag]


S(0x483660, 'ZPlayer::ForceLHandItem(ZItem*, bool)', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 309; all calls are virtual')
