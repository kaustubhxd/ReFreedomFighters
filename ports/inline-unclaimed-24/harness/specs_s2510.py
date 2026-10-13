"""specs_s2510.py - decomp area 24, batch 2510.
0x54ab40: cdecl no args, returns SetEvent(*0x713d28); the SetEvent import is a Python stub returning 0 or 1 (logged with its handle).
0x5a5c50: thiscall no args, plain ret; calls 0x5ef050 (hooked, thiscall, 1 arg, pops 4) on [this+0x62c] with 0; returns its eax."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _ev(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x713d28, r.getrandbits(32))
    v = r.choice([0, 1])

    def set_(em, rr):
        em.calllog.append(('SetEvent', 0, 0, (em.arg32(0),)))
        em.ret(eax=v, argbytes=4)

    c.emu.stub_import('SetEvent', set_)
    return []


def _fwd(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ef050, 1, ret=r.getrandbits(32), this=True, pop=4)
    o = rnd(c, 0x640)
    t = rnd(c, 0x40)
    c.emu.w32(o + 0x62c, t)
    return [o]


S(0x54ab40, 'GUESS SetEvent(*0x713d28)', 'cdecl', None, ret='eax', gen=_ev, note='batch2510')
S(0x5a5c50, 'GUESS forward to 0x5ef050 with 0', 'thiscall', None, ret='eax', gen=_fwd, note='batch2510')
