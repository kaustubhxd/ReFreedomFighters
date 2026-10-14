"""specs_s34006.py - cascade escalation batch 34006: 0x47fb90 (slot 0x14 tail jump when [this+4] != 0, else plain ret; half the cases have
[this+4] == 0) and the thiscall(v) ret 4 setters 0x446780 (+0x6c), 0x4682d0 (+0x1d6), 0x470c80 (+0x64)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g47fb90(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x14: pystub(c, 2, ret=r.getrandbits(32), this=True)})
    c.emu.w32(me + 4, 0 if r.random() < 0.5 else r.getrandbits(32))
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _setter(c):
    clear_hooks(c)
    return [rnd(c, 0x200), c.rng.getrandbits(32)]


S(0x47fb90, 'GUESS conditional slot 0x14 forward', 'thiscall', None, ret='eax', gen=_g47fb90, note='batch34006')
S(0x446780, 'GUESS set dword +0x6c', 'thiscall', None, ret=None, gen=_setter, note='batch34006')
S(0x4682d0, 'GUESS set dword +0x1d6', 'thiscall', None, ret=None, gen=_setter, note='batch34006')
S(0x470c80, 'GUESS set dword +0x64', 'thiscall', None, ret=None, gen=_setter, note='batch34006')
