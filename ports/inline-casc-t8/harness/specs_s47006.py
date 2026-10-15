"""specs_s47006.py - cascade t8 batch 47006: 0x566650 (read config ids by name, look up objects), 0x470420 (re-register an object in two slots)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g566650(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    objs = [0] + [obj(c, 0x20, {0x2c: pystub(c, 0, this=True)}) for _ in range(3)]
    rd = obj(c, 0x20, {0x88: pystub(c, 2, this=True, nullflag=(1,),
                                    side=lambda em, k: em.w32(em.arg32(1), r.getrandbits(32)) if r.random() < 0.8 else None)})
    named = obj(c, 0xb00, {0x0: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32))})
    so = sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=rd),
                                0x58: pystub(c, 1, this=True, ret=lambda em, k: r.choice(objs))}, table_size=0xb00)
    tbl = e.r32(so + 0x9b)
    e.w32(tbl + 0xae4, named)
    c44 = obj(c, 0x20, {0x130: pystub(c, 3, this=True)})
    me = obj(c, 0x1000, {0x64: pystub(c, 1, this=True)})
    e.w32(me + 0x44, c44)
    return [me]


def _g470420(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4711f0, 2, this=True)

    def mk():
        inner = rnd(c, 0x80)
        o = obj(c, 0x20, {0x2c: pystub(c, 0, this=True), 0x128: pystub(c, 3, this=True)})
        e.w32(o + 8, inner)
        return o
    pool = [0, mk(), mk(), mk()]
    p = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101])),
                      0x420: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x80000000]))})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: r.choice(pool))})
    me = obj(c, 0x200, {0x2f4: pystub(c, 0, this=True, ret=p if r.random() < 0.8 else 0),
                        0x374: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))})
    e.wbytes(me + 0xfd, bytes(r.getrandbits(8) for _ in range(4)))
    e.wbytes(me + 0x101, bytes(r.getrandbits(8) for _ in range(4)))
    return [me]


S(0x566650, 'GUESS read config ids look up objects', 'thiscall', None, ret=None, gen=_g566650, note='batch47006')
S(0x470420, 'GUESS re-register object in two slots', 'thiscall', None, ret='eax', gen=_g470420, note='batch47006')
