"""specs_s1660.py - residue 13 batch 1660: 0x476200 (DBREAD reader). The three reader operators are hooked by address:
0x4e5e80 returns a float in ST0, 0x4e5e40 returns a word in AX (high bits random), 0x4e5e60 returns a dword and is called
twice (the second value is a separate random draw, so its zero test is exercised)."""
import struct
from pilot import S
from sthelp import rnd, Seq, clear_hooks, HOOKED


def _float_hook(c, addr, val):
    def h(e, r):
        e.ret(eax=0, argbytes=0, st0=val)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _dw_hook(c, addr, vals):
    cnt = c.emu.alloc(4, 4)

    def h(e, r):
        i = e.r32(cnt)
        e.w32(cnt, i + 1)
        e.ret(eax=vals[i % len(vals)], argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _gen(c):
    r = c.rng
    clear_hooks(c)
    fv = r.uniform(-100, 100) if r.random() < 0.8 else r.choice([0.0, -0.0, float('nan'), float('inf')])
    _float_hook(c, 0x4e5e80, fv)
    _dw_hook(c, 0x4e5e40, [r.getrandbits(32)])
    zero_or_not = [0, r.getrandbits(32)]
    _dw_hook(c, 0x4e5e60, [r.getrandbits(32), r.choice(zero_or_not)])
    me = rnd(c, 0x100)
    reader = rnd(c, 0x40)
    return [me, reader]


S(0x476200, 'GUESS FUN_476200', 'thiscall', None, ret=None, gen=_gen, note='batch1660; DBREAD operators hooked')
