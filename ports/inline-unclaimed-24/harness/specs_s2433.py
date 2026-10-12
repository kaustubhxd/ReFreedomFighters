"""specs_s2433.py - decomp area 24, batch 2433.
0x420570 ZSysInterfaceGC::CloseAllWindows(), thiscall, plain ret: while the head at +0x190f is set, slot 0 of the head
is called with 1. The recorder unlinks its node (the head becomes 0), so the loop runs once per case.
0x44b8b0 (unnamed), thiscall, ret 4: the object at (0x70039c)+0x1a9f gets slot 0x12c with (the dword at this+0x38, the
argument); the result is stored at this+0x38. Recorder, two arguments."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks


def _close(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = rnd(c, 0x2000)
    node = obj(c, 0x40, {0: pystub(c, 1, side=lambda em, k: em.w32(so + 0x190f, 0))})
    e.w32(so + 0x190f, node if r.random() < 0.7 else 0)
    return [so]


def _slot12c(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    tab = obj(c, 0x40, {0x12c: pystub(c, 2, ret=lambda emu, k: r.getrandbits(32))})
    e.w32(so + 0x1a9f, tab)
    o = rnd(c, 0x40)
    return [o, r.getrandbits(32)]


S(0x420570, 'ZSysInterfaceGC::CloseAllWindows', 'thiscall', None, ret=None, gen=_close, note='batch2433')
S(0x44b8b0, 'GUESS: slot 0x12c caller on the sys table object (0x44b8b0)', 'thiscall', None, ret='eax', gen=_slot12c, note='batch2433')
