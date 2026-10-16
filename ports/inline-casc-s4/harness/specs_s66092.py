"""specs_s66092.py - cascade s4 batch 66092: 0x4437b0 (switch an owner on or off; the y slots are ret 4 callees that eat the pushed esi)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4437b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    flag = r.choice([0, 1, 1, 0, 2, 0x100, 0x101])
    Rt = rnd(c, 0x20)
    G = obj(c, 0x40, {0x2f0: pystub(c, 1, this=True, pop=4), 0x2f4: pystub(c, 1, this=True, pop=4)}, nslots=0x2f8 // 4)
    y = obj(c, 0x40, {0x2cc: pystub(c, 0, this=True, pop=4), 0x2c8: pystub(c, 0, this=True, pop=4)}, nslots=0x2d0 // 4)
    gret = G if r.random() < 0.7 else 0
    yret = y if r.random() < 0.7 else 0
    hook_rec(c, 0x4daff0, 0, this=True, ret=gret)
    hook_rec(c, 0x4db7e0, 0, this=True, ret=yret)
    hook_rec(c, 0x443c80, 1, this=True, pop=4)
    hook_rec(c, 0x442050, 1, this=True, pop=4)
    Q = rnd(c, 0x20)
    me = obj(c, 0x100, {0x20: pystub(c, 0, ret=(Q if r.random() < 0.85 else 0), this=True, pop=0)}, nslots=0x24 // 4)
    cur = r.choice([0, 1, flag & 0xff, (flag & 0xff) ^ 1])
    e.wbytes(me + 0x5c, bytes([cur]))
    n = r.choice([0, 1, 2, 3])
    lst = e.alloc(4 * n + 8, 4)
    e.w32(lst, n)
    e.wbytes(lst, n.to_bytes(2, 'little'))
    for i in range(n):
        e.w32(lst + 4 + 4 * i, rnd(c, 0x10))
    e.w32(me + 0x7b, lst if r.random() < 0.85 else 0)
    return [me, flag]


S(0x4437b0, 'GUESS switch owner on or off', 'thiscall', None, ret=None, gen=_g4437b0, note='batch66092')
