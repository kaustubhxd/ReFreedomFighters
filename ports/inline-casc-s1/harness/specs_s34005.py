"""specs_s34005.py - cascade escalation batch 34005: 0x4cbe40 (ecx = [this+0x18], jump to the unaligned code pointer at [this+0x2f]) and the
vtable thunks 0x45faf0 (slot 0x128), 0x463930 (slot 0x7c). Targets are recorder stubs (ECX and 2 stack args recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4cbe40(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x60)
    c.emu.wbytes(me + 0x2f, pystub(c, 2, ret=r.getrandbits(32), this=True).to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _thunk(slot):
    def g(c):
        clear_hooks(c)
        r = c.rng
        me = obj(c, 0x40, {slot: pystub(c, 2, ret=r.getrandbits(32), this=True)})
        return [me, r.getrandbits(32), r.getrandbits(32)]
    return g


S(0x4cbe40, 'GUESS this=[+0x18], jump [+0x2f]', 'thiscall', None, ret='eax', gen=_g4cbe40, note='batch34005')
S(0x45faf0, 'GUESS vtable tail thunk slot 0x128', 'thiscall', None, ret='eax', gen=_thunk(0x128), note='batch34005')
S(0x463930, 'GUESS vtable tail thunk slot 0x7c', 'thiscall', None, ret='eax', gen=_thunk(0x7c), note='batch34005')
