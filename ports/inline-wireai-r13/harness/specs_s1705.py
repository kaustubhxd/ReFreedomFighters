"""specs_s1705.py - residue 13 batch 1705: eight leaf functions. 0x4478d0 (the tail target of 0x4529d0) is hooked (no stack
arguments, random eax). Float returns are read from st0 (ret='st0')."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook


def _self(c):
    r = c.rng
    clear_hooks(c)
    me = rnd(c, 0x22040)
    c.emu.wf32(me + 0xc, r.uniform(-100, 100))
    # the bool at +0x22030 is a dword; the neighbouring bytes are set so that a shifted read gives a different answer
    c.emu.w32(me + 0x22030, r.choice([0, 0, 1, r.getrandbits(32)]))
    c.emu.w8(me + 0x22034, r.choice([0, 1]))
    return [me]


def _tail(c):
    r = c.rng
    args = _self(c)                     # _self clears the hooks, so the tail hook is installed after it
    hook(c, Seq(c), 0x4478d0, 0, ret=r.getrandbits(32), this=True, pop=True)
    return args


S(0x524390, 'GUESS FUN_524390', 'thiscall', None, ret='st0', gen=_self, note='batch1705; float getter')
S(0x614ed0, 'GUESS FUN_614ed0', 'thiscall', None, ret='eax', gen=_self, note='batch1705; constant')
S(0x654710, 'GUESS FUN_654710', 'thiscall', None, ret='eax', gen=_self, note='batch1705; constant')
S(0x51c550, 'GUESS FUN_51c550', 'thiscall', None, ret='st0', gen=_self, note='batch1705; global float')
S(0x60d810, 'GUESS FUN_60d810', 'thiscall', None, ret='eax', gen=_self, note='batch1705; this+0x94')
S(0x616a50, 'GUESS FUN_616a50', 'thiscall', None, ret=None, gen=_self, note='batch1705; vtable store')
S(0x4529d0, 'GUESS FUN_4529d0', 'thiscall', None, ret='eax', gen=_tail, note='batch1705; vtable store and tail jump 0x4478d0 (hooked)')
S(0x613350, 'GUESS FUN_613350', 'thiscall', None, ret='al', gen=_self, note='batch1705; bool at +0x22030')
