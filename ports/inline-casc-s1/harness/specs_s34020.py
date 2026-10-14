"""specs_s34020.py - cascade tier E, batch 34020.
0x639d80: callees 0x634273 / 0x634d22 (cdecl, pop 0) and 0x41e290 (returns a fresh buffer) are recorders; the owned flag byte +0x31 is random, n includes values whose *4 overflows.
0x654c10: engine slot 0x1b0 returns an object or 0 (slot 0xc returns 0/1, slot 0x14 a recorder); the engine block is random bytes so the &= 0x7f writes are visible.
0x455020: hooked 0x440e10; stream slots 0x48 (writes a count -2..5) and 0x40 (writes an id) are stack-pointer recorders; engine table slot 0x58 and [this+0x5c] slot 4 recorders.
0x456e60: 256-entry table at this+0x1d with random non-zero keys, an empty slot at a random index (or none: full-table path through the logger object at 0x700390), x equal to an
existing key in a third of the cases; assert hook set.
0x48f9a0: engine slot 0x190 returns an object whose slot 0x184 is a recorder (ECX = counter % 3 and four caller-popped stack args); count 0..8."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g639d80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x634d22, 3, pop=0)
    hook_rec(c, 0x41e290, 1, ret=rnd(c, 0x20), pop=0)
    me = rnd(c, 0x60)
    c.emu.wbytes(me + 0x31, bytes([r.choice([0, 1, 1, r.getrandbits(8) | 1])]))
    c.emu.wbytes(me + 0x2d, r.getrandbits(32).to_bytes(4, 'little'))
    n = r.choice([0, 1, 5, 0x40000000, 0x40000001, 0xffffffff, r.getrandbits(32), r.randint(0, 100)])
    return [me, r.getrandbits(32), n, r.choice([0, 1, 2, 0x100, r.getrandbits(32)])]


def _g654c10(c):
    clear_hooks(c)
    r = c.rng
    s = 0 if r.random() < 0.3 else obj(c, 0x20, {0xc: pystub(c, 0, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True),
                                                  0x14: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x10)
    so = sysobj(c, slots={0x1b0: pystub(c, 0, ret=s, this=True)})
    c.emu.wbytes(so + 0x6e, bytes([r.choice([0, 0, 1, 0x80])]))
    a = r.choice([0, 1, 0x7f, 0xff, 0x100, 0x101, -1, -0x100, r.getrandbits(32), r.randint(0, 0xff)]) & 0xffffffff
    return [a, r.getrandbits(32)]


def _g455020(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x440e10, 1, this=True)

    def cnt(em, k):
        em.w32(em.arg32(0), r.choice([-2, 0, 1, 3, 5]) & 0xffffffff)

    def idw(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    s = obj(c, 0x20, {0x48: pystub(c, 1, this=True, side=cnt, stackmark=(0,)),
                      0x40: pystub(c, 1, this=True, side=idw, stackmark=(0,))}, nslots=0x20)
    lst = obj(c, 0x20, {4: pystub(c, 1, this=True)}, nslots=4)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x5c, lst)
    return [me, s]


def _g456e60(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    me = rnd(c, 0x1d + 8 * 256 + 0x10)
    keys = [r.getrandbits(32) | 1 for _ in range(256)]
    k = r.random()
    empty = -1 if k < 0.2 else r.randrange(0, 256) if k < 0.6 else r.randrange(0, 6)
    for i, key in enumerate(keys):
        c.emu.wbytes(me + 0x1d + 8 * i, (0 if i == empty else key).to_bytes(4, 'little'))
    live = [keys[i] for i in range(256) if i != empty]
    x = r.choice(live) if r.random() < 0.35 else r.getrandbits(32)
    return [me, x]


def _g48f9a0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x184: pystub(c, 4, this=True, pop=0)}, nslots=0x1a0)
    sysobj(c, slots={0x190: pystub(c, 0, ret=o, this=True)})
    me = rnd(c, 0x20)
    c.emu.w32(me + 4, r.choice([0, 1, 2, 3, 4, 7, 8, r.randint(0, 8)]))
    return [me]


S(0x639d80, 'GUESS set owned or borrowed array', 'thiscall', None, ret=None, gen=_g639d80, note='batch34020')
S(0x654c10, 'GUESS forward key event or clear key bits', 'stdcall', None, ret=None, gen=_g654c10, note='batch34020')
S(0x455020, 'GUESS rebuild list from stream', 'thiscall', None, ret='al', gen=_g455020, note='batch34020')
S(0x456e60, 'GUESS find or insert key in 256-slot table', 'thiscall', None, ret='eax', gen=_g456e60, note='batch34020')
S(0x48f9a0, 'GUESS lay out 3-column grid', 'thiscall', None, ret=None, gen=_g48f9a0, note='batch34020')
