"""specs_s34023.py - cascade tier E, batch 34023.
0x4fa8a0: [this+0x70] equals v in a quarter of the cases; this slots 0x2c4 / 0x2f4, the object's slot 0x2dc and engine table slot 0x4c (four stack args, one a stack pointer) are
recorders; [this+0x74] random.
0x50f7d0 (stdcall): hooked 0x5003d0 returns an entry whose kind byte +4 is 3, 4 or another value; kind 4: [e] points at an object with slot 0x34 recorder; the logger object at
0x700390 and the assert hook are set; engine table slot 0xa0 is a recorder returning random."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g4fa8a0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x2dc: pystub(c, 1, this=True)}, nslots=0x300)
    sysobj(c, table_slots={0x4c: pystub(c, 4, this=True, ret=r.getrandbits(32), stackmark=(1,))}, table_size=0x80)
    me = obj(c, 0x100, {0x2c4: pystub(c, 0, ret=o, this=True), 0x2f4: pystub(c, 1, this=True)}, nslots=0x300)
    v = r.choice([0, 1, 2, 0x10, 0x80000000, r.getrandbits(32)])
    if r.random() < 0.25:
        c.emu.w32(me + 0x70, v)
    return [me, v]


def _g50f7d0(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    q = obj(c, 0x20, {0x34: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x20)
    e = rnd(c, 0x20)
    kind = r.choice([3, 4, 4, 0, 1, 2, 5, 0x103, r.getrandbits(8)])
    c.emu.wbytes(e + 4, bytes([kind & 0xff]))
    c.emu.w32(e, q if (kind & 0xff) == 4 else r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, ret=e, this=True)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    sysobj(c, table_slots={0xa0: pystub(c, 1, ret=r.getrandbits(32), this=True)}, table_size=0x100)
    a = rnd(c, 0x20)
    c.emu.w32(a + 4, rnd(c, 0x20))
    return [a]


S(0x4fa8a0, 'GUESS change mode and notify', 'thiscall', None, ret=None, gen=_g4fa8a0, note='batch34023')
S(0x50f7d0, 'GUESS resolve value by entry kind, forward to table slot 0xa0', 'stdcall', None, ret='eax', gen=_g50f7d0, note='batch34023')
