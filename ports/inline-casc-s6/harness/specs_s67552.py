"""specs_s67552.py - cascade s6 batch 67552 (0x62cd30, cdecl(ctx, code, off, n, obj), returns eax). The compare callback obj[0x1c] is a cdecl stub logging its 4 arguments and answering from a
random sequence (matching a single keyword most of the time); codes come from 0xf / 0x14 / 0x1b / 0x1c / other; ctx[0xc] is zero or not."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g62cd30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    match = r.choice([0, 1, 2, 3, 4])   # 1/2/3: which keyword matches (4: none), 0: first

    def cb(em, res_):
        k = len([x for x in em.calllog if x[0] == 'cb'])
        em.calllog.append(('cb', tuple(em.arg32(i) for i in range(4))))
        em.ret(eax=1 if (k + 1) == match else 0, argbytes=0)
    obj = rnd(c, 0x60)
    _w(c, obj + 0x1c, e.stub_fn('recorder', cb))
    _w(c, obj + 0x44, r.getrandbits(32))
    ctx = rnd(c, 0x20)
    _w(c, ctx + 0xc, r.choice([0, 0, 5]))
    return [ctx, r.choice([0xf, 0x14, 0x14, 0x14, 0x1b, 0x1c, 0x1c, 7]), r.getrandbits(32), r.randrange(0, 40), obj]


S(0x62cd30, 'GUESS classify_token', 'cdecl', None, ret='eax', gen=_g62cd30, note='batch67552')
