"""specs_s210042.py - Sonnet-w3a: serialize list of typed records, kind switch with engine lookups; callees hooked."""
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


def g603990(c):
    clear_hooks(c)
    hook_rec(c, 0x5f9db0, 1, ret=_r(c), this=True)
    a = obj(c, 0x40, {0: pystub(c, 1, ret=_r(c), this=True)}, nslots=4)
    k = c.rng.choice([0, 1, 2, 3])
    recs = rnd(c, 0x40)
    for i in range(k):
        o = obj(c, 0x40, {0x38: pystub(c, 0, ret=_r(c), this=True), 0x3c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
        c.emu.w32(recs + 8 * i, o)
        c.emu.wbytes(recs + 8 * i + 4, bytes([c.rng.choice([4, 4, 0, 3])]))
    t = obj(c, 0x40, {0x38: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20)
    c.emu.w32(t + 0xc, recs); c.emu.w32(t + 0x14, k)
    return [t, a]


def g50dd50(c):
    clear_hooks(c)
    _assert_hook(c)
    o = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=o, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    x = rnd(c, 8)
    kind = c.rng.choice([3, 4, 4, 3, 0, 7])
    c.emu.wbytes(x + 4, bytes([kind]))
    if kind == 4:
        c.emu.w32(x, obj(c, 0x40, {0x34: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20))
    z = rnd(c, 8); c.emu.wbytes(z + 4, bytes([c.rng.choice([0, 1, 1, 2, 5])]))
    q = obj(c, 0x40, {0x25c: pystub(c, 2, ret=_r(c), this=True)}, nslots=0xa0)
    mg = obj(c, 0xb00, {0x4c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x30)
    c.emu.w32(mg + 0xadc, q)
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    hook_rec(c, 0x5003d0, 1, ret=lambda e, k: x if k == 0 else z, this=True)
    a = rnd(c, 0x10); c.emu.w32(a + 4, rnd(c, 0x20)); c.emu.w32(a + 8, rnd(c, 0x20))
    return [a]


S(0x603990, 'serialize_typed_records', 'thiscall', None, ret=None, gen=g603990, note='batch210042')
S(0x50dd50, 'kind_switch_engine_lookups', 'stdcall', None, ret='eax', gen=g50dd50, note='batch210042')
