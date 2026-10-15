"""specs_s43005.py - t4 (Sonnet) batch 43005. 0x526c60: 0x5168b0 hooked (records this); 0x6528a0: sprintf 0x42ac56 hooked, IAT slot 0x67618c is a logging stub
(returns nonzero for the first k calls); 0x563490: chain of slot stubs."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _fl(r):
    k = r.random()
    if k < 0.06:
        return r.choice([0.0, -0.0, float('nan'), float('inf'), float('-inf')])
    if k < 0.2:
        return r.uniform(-1e5, 1e5)
    return r.uniform(-20, 20)


def _cf(c, addr):
    return struct.unpack('<f', c.emu.rbytes(addr, 4))[0]


def _g526c60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x1700)
    # constants A (0x681dc4), B (0x679544), E (0x69c69c) vary per case so the max and the threshold edge are observable
    for addr in (0x681dc4, 0x679544, 0x69c69c):
        if r.random() < 0.8:
            e.w32(addr, _fb(r.choice([_cf(c, addr), r.uniform(-5, 5), r.uniform(0, 100), _fl(r)])))
    ct = _cf(c, 0x67cd40)
    cd = _cf(c, 0x680a84)
    e.w32(me + 0x68, _fb(r.choice([ct, ct + 1, ct - 1, _fl(r), abs(_fl(r)) + 0.01])))
    e.w32(me + 0x6c, _fb(r.choice([cd, cd + 1, cd - 1, _fl(r)])))
    e.wbytes(me + 0x12f7, struct.pack('<i', r.choice([0, 1, 2, 3, 5, 8, -1, -5, r.randrange(0, 9)])))
    hook_rec(c, 0x5168b0, 0, this=True)
    return [me]


def _g6528a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7f6410, r.choice([0, 0, 0, 1, _w(c)]))
    n = r.choice([0, 1, 2, 5, 999, 1000, 2000, r.randrange(0, 30)])

    def pr(em, k):
        em.wbytes(em.arg32(0), b'Cls%d\0' % k)
    hook_rec(c, 0x42ac56, 3, pop=0, side=pr)
    e.w32(0x67618c, pystub(c, 3, stackmark=(2,), ret=lambda em, k: 1 if k < n else 0,
                            side=lambda em, k: em.calllog.append(('gci', em.r32(em.arg32(2))))))
    return [_w(c)]


def _g563490(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o3 = obj(c, 0x20, {0x60: pystub(c, 1, this=True, ret=_w(c))})
    o2 = obj(c, 0x20, {0x60: pystub(c, 1, this=True, ret=o3)})
    o1 = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, ret=o2)})
    a = obj(c, 0x20, {0x3c: pystub(c, 1, this=True, ret=o1), 0x44: pystub(c, 1, this=True)})
    me = rnd(c, 0x100)
    return [me, a]


S(0x526c60, 'GUESS compute scale and push into entries', 'thiscall', None, ret=None, gen=_g526c60, note='batch43005')
S(0x6528a0, 'GUESS find unused window class name', 'thiscall', None, ret=None, gen=_g6528a0, note='batch43005')
S(0x563490, 'GUESS apply settings through slot chain', 'thiscall', None, ret='al', gen=_g563490, note='batch43005')
