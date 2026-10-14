"""specs_s31125.py - batch 31125."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g5aa060(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5abcd0, 0, ret=r.choice([0, 1, 0x100, r32(c)]), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x5acac0, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    hook_rec(c, 0x5ac940, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    hook_rec(c, 0x5edb00, 1, ret=r32(c), pop=4, this=True)
    t = obj(c, 0x40, {8: pystub(c, 0, ret=r32(c), this=True)}, nslots=0x10)
    me = rnd(c, 0x670)
    c.emu.w32(me + 0x640, r32(c))
    c.emu.w32(me + 0x470, t)
    c.emu.w32(me + 0x658, r.choice([0, 1, 0x100, r32(c)]))
    flag = rnd(c, 0x10)
    c.emu.w32(flag, r.choice([0, 0, 1, 0x100, r32(c)]))
    return [me, flag]


def g5bf940(c):
    clear_hooks(c)
    r = c.rng
    fl = lambda: r.choice([0, 1, 0x100, r32(c)])
    mk = lambda: r.choice([0, obj(c, 0x40, {0x1e0: pystub(c, 1, ret=fl(), this=True)}, nslots=0x100)])
    outs = [mk(), mk()]
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda e, k: outs[k % 2], this=True, side=clob(c))})
    me = rnd(c, 0x80)
    return [me][:1]


def g462460(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x18: pystub(c, 0, ret=r32(c), this=True)})
    L = r.choice([0, 1, 3, 7])
    s = rnd(c, 0x20)
    bs = [r.randrange(1, 256) for _ in range(L)] + [0, 0, 0, 0]
    for i in range(L + 1):
        c.emu.w32(s + i, bs[i] | bs[i + 1] << 8 | bs[i + 2] << 16 | bs[i + 3] << 24)
    return [rnd(c, 0x80), r32(c), s]


def g46f240(c):
    clear_hooks(c)
    r = c.rng
    vals = [r32(c) for _ in range(3)]
    G = obj(c, 0x40, {0x60: pystub(c, 2, ret=lambda e, k: vals[k % 3], this=True)}, nslots=0x40)
    so = sysobj(c)
    c.emu.w32(so + 0x1a9f, r.choice([0, G, G]))
    q = obj(c, 0x40, {0x378: pystub(c, 0, ret=r.choice([0, r32(c) | 1]), this=True)}, nslots=0x200)
    me = obj(c, 0xa0, {0x350: pystub(c, 0, ret=q, this=True, side=clob(c))}, nslots=0x200)
    return [me]


S(0x5aa060, 'GUESS toggle on flag: 5abcd0/5acac0/5ac940 and notify this[0x470] via 5edb00 and slot 8', 'thiscall', None, ret='eax', gen=g5aa060, note='batch31125')
S(0x5bf940, 'GUESS resolve two ids via sys slot 0x58 and cache flag 0x800001a', 'thiscall', None, ret='eax', gen=g5bf940, note='batch31125')
S(0x462460, 'GUESS init record: zero fields, slot 0x18 stamp, copy name', 'thiscall', None, ret='eax', gen=g462460, note='batch31125')
S(0x46f240, 'GUESS look up three named handles via global+0x1a9f slot 0x60', 'thiscall', None, ret='eax', gen=g46f240, note='batch31125')
