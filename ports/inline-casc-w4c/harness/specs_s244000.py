"""specs_s244000.py - Sonnet-w4c batch 244000: tiny tier-4 thunks/getters. Slot stubs and hooked callees record this+args."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _vthunk(off, nargs=1):
    def g(c):
        clear_hooks(c)
        me = obj(c, 0x40, {off: pystub(c, nargs, ret=c.rng.getrandbits(32), this=True)})
        return [me] + [c.rng.getrandbits(32) for _ in range(nargs)]
    return g


def _jthunk(target, nargs, this=True):
    def g(c):
        clear_hooks(c)
        hook_rec(c, target, nargs, ret=c.rng.getrandbits(32), this=this)
        return [rnd(c, 0x80)] + [c.rng.getrandbits(32) for _ in range(nargs)]
    return g


def _g64c750(c):
    clear_hooks(c)
    return []


def _gself(c):
    clear_hooks(c)
    return [rnd(c, 0x100)]


def _g65f5d0(c):
    clear_hooks(c)
    inner = rnd(c, 0x10090)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0xc, inner)
    return [me]


S(0x5332e0, 'GUESS thunk to 0x536640', 'thiscall', None, ret='eax', gen=_jthunk(0x536640, 1), note='batch244000')
S(0x4f04d0, 'GUESS vcall thunk slot 0x158', 'thiscall', None, ret='eax', gen=_vthunk(0x158), note='batch244000')
S(0x536640, 'GUESS vcall thunk slot 0x18c', 'thiscall', None, ret='eax', gen=_vthunk(0x18c), note='batch244000')
S(0x54dcd0, 'GUESS vcall thunk slot 0x54', 'thiscall', None, ret='eax', gen=_vthunk(0x54), note='batch244000')
S(0x64c750, 'GUESS returns 0x7f', 'stdcall', None, ret='eax', gen=_g64c750, note='batch244000')
S(0x64fb70, 'GUESS getter +0x8c', 'thiscall', None, ret='eax', gen=_gself, note='batch244000')
S(0x429b00, 'GUESS clear byte +0x75, return true', 'thiscall', None, ret='al', gen=_gself, note='batch244000')
S(0x473a60, 'GUESS thunk to 0x462640', 'thiscall', None, ret='eax', gen=_jthunk(0x462640, 4), note='batch244000')
S(0x4ef200, 'GUESS thunk to 0x43f8c0', 'thiscall', None, ret='eax', gen=_jthunk(0x43f8c0, 1), note='batch244000')
S(0x4f5160, 'GUESS thunk to 0x4ef200', 'thiscall', None, ret='eax', gen=_jthunk(0x4ef200, 1), note='batch244000')
S(0x4f5840, 'GUESS thunk to 0x4efdd0', 'thiscall', None, ret='eax', gen=_jthunk(0x4efdd0, 4), note='batch244000')
S(0x65f5d0, 'GUESS [this+0xc] field difference', 'thiscall', None, ret='eax', gen=_g65f5d0, note='batch244000')
