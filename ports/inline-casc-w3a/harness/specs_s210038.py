"""specs_s210038.py - Sonnet-w3a: stored-value lookup, flag-driven engine update; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g555290(c):
    clear_hooks(c)
    _assert_hook(c)
    o2 = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=o2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    x = rnd(c, 8); c.emu.wbytes(x + 4, bytes([c.rng.choice([0, 1, 1, 0, 5])]))
    y = rnd(c, 8); c.emu.w32(y, c.rng.choice([0, 1, 7]))
    m = rnd(c, 0x2000)
    o = 0 if c.rng.random() < 0.2 else rnd(c, 0x860)
    if o: _ub(c, o + 0x852, 0 if c.rng.random() < 0.25 else m)
    mg = obj(c, 0x40, {0x58: pystub(c, 1, ret=o, this=True)}, nslots=0x20)
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    hook_rec(c, 0x5003d0, 1, ret=lambda e, k: [x, y, rnd(c, 8)][min(k, 2)], this=True)
    hook_rec(c, 0x5002f0, 1, ret=_r(c), this=True)
    hook_rec(c, 0x5979c0, 0, ret=_r(c), this=True)
    a = rnd(c, 0x10); c.emu.w32(a + 4, rnd(c, 0x20)); c.emu.w32(a + 8, rnd(c, 0x20))
    return [a]


def g44c2b0(c):
    clear_hooks(c)
    A = rnd(c, 0x60)
    c.emu.w32(A + 0x3c, c.rng.choice([0, 0x400, 0x800, _r(c), _r(c) & ~0x400, _r(c) | 0x400]))
    B = rnd(c, 0x60); c.emu.w32(B + 0x40, c.rng.choice([0, 2, 3, 0xffffffff]))
    t = obj(c, 0x40, {0x210: pystub(c, 1, ret=_r(c), this=True), 0xb4: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x90)
    c.emu.w32(t + 8, A); c.emu.w32(t + 0x18, B); c.emu.w32(t + 0x1c, _r(c))
    e = 0 if c.rng.random() < 0.2 else obj(c, 0x40, {0x48: pystub(c, 1, ret=c.rng.choice([0, 1, 0x100, 0x101]), this=True)}, nslots=0x30)
    mg = rnd(c, 0xbc0); c.emu.wbytes(mg + 0xbaf, bytes([c.rng.choice([0, 1, 1])]))
    eng = rnd(c, 0x1b00); _ub(c, eng + 0x1a9f, e); _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    return [t]


S(0x555290, 'lookup_value_minus_offset', 'stdcall', None, ret='eax', gen=g555290, note='batch210038')
S(0x44c2b0, 'flag_driven_engine_update', 'thiscall', None, ret='eax', gen=g44c2b0, note='batch210038')
