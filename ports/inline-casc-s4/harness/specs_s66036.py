"""specs_s66036.py - cascade s4 batch 66036: 0x470a00 (conditionally bind a script handler to an actor)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g470a00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = obj(c, 0x30, {0x32c: pystub(c, 0, this=True, ret=r.choice([0, 1, 0x100, 0x101]))})
    x = obj(c, 0x30, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100])),
                      0x420: pystub(c, 0, this=True, ret=r.choice([0, 1, 2]))})
    xr = r.choice([x, x, 0])

    def s88(em, rr):
        em.calllog.append(('s88', em.arg32(0)))
        em.w32(em.arg32(1), r.getrandbits(32))
        em.ret(eax=0, argbytes=8)
    o = obj(c, 0x30, {0x88: e.stub_fn('s88', s88)})
    newflag = r.choice([None, 0, 1, 7])

    def s114(em, rr):
        em.calllog.append(('s114', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.rbytes(em.arg32(4), 1)[0]))
        if newflag is not None:
            em.wbytes(em.arg32(4), bytes([newflag]))
        em.ret(eax=r.choice([0x12345678, 0xffff, 0x10000]), argbytes=20)
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x114: e.stub_fn('s114', s114)})
    t = obj(c, 0x30, {0x350: pystub(c, 0, this=True, ret=a), 0x2f4: pystub(c, 0, this=True, ret=xr),
                      0x354: pystub(c, 0, this=True, ret=r.choice([0, 1, 0x100, 0x101])),
                      0x12c: pystub(c, 2, this=True)})
    return [t]


S(0x470a00, 'GUESS conditionally bind a script handler to an actor', 'thiscall', None, ret='al', gen=_g470a00, note='batch66036')
