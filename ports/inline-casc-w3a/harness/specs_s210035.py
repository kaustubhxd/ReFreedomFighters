"""specs_s210035.py - Sonnet-w3a: iterator step with assert, engine lookup store, pool slot find-or-create; callees hooked."""
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


def _report(c, line_args):
    o = obj(c, 0x40, {0x2c: pystub(c, line_args, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=o, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)


def g4cf2d0(c):
    clear_hooks(c)
    _assert_hook(c); _report(c, 2)
    t = rnd(c, 0x40)
    c.emu.w32(t + 0xc, c.rng.choice([0, 1, 5, 0xffffffff, 0x80000000]))
    m = rnd(c, 0x20); c.emu.w32(m + 8, c.rng.choice([0, 1, 2]))
    c.emu.w32(t + 8, m); c.emu.w32(t + 0x10, c.rng.choice([0, 1, 2, 3])); c.emu.w32(t + 0x18, c.rng.choice([1, 2, 4]))
    e = rnd(c, 8)
    n2 = rnd(c, 0x30); c.emu.w32(n2 + 4, 0 if c.rng.random() < 0.4 else c.rng.choice([0, 1]))
    n1 = rnd(c, 0x30); c.emu.w32(n1 + 4, n2 if c.rng.random() < 0.7 else 0)
    first = n1 if c.rng.random() < 0.9 else 0
    c.emu.w32(e, first)
    c.emu.w32(e + 4, c.rng.choice([0, 1, 2, 3, 5]) if first else 7)
    return [t, e]


def g511090(c):
    clear_hooks(c)
    _assert_hook(c); _report(c, 3)
    a = rnd(c, 0x10); c.emu.w32(a + 4, rnd(c, 0x20)); c.emu.w32(a + 8, rnd(c, 0x20))
    z = rnd(c, 0x10); c.emu.wbytes(z + 4, bytes([c.rng.choice([0, 1, 2, 5])]))
    k = [0]
    hook_rec(c, 0x5003d0, 1, ret=lambda e, n: rnd(c, 8) if n == 0 else z, this=True)
    hook_rec(c, 0x506040, 0, ret=_r(c), this=True)
    hook_rec(c, 0x5002f0, 1, ret=_r(c), this=True)
    eo = 0 if c.rng.random() < 0.2 else obj(c, 0x40, {0x6c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    eng = rnd(c, 0x1b00); _ub(c, eng + 0x1a9f, eo)
    c.emu.w32(0x70039c, eng)
    return [a]


def g4d0590(c):
    clear_hooks(c)
    _assert_hook(c); _report(c, 3)
    a_val = c.rng.choice([0, 1, 5, 100, 0xffffffff])
    q = rnd(c, 0x20); c.emu.w32(q + 8, c.rng.choice([0, 1, 5, 100, 0xffffffff, 0x80000000]))
    p = rnd(c, 0x40); _ub(c, p + 0x11, q)
    pp = 0 if c.rng.random() < 0.3 else p
    pp2 = 0 if c.rng.random() < 0.4 else p
    t = rnd(c, 0x200)
    vt = c.emu.r32(obj(c, 0x40, {0xc: pystub(c, 2, ret=pp, this=True)}, nslots=0x10))
    c.emu.w32(t + 0x1cc, vt)
    hook_rec(c, 0x4cfbe0, 0, ret=pp2, this=True)
    c.emu.w32(0x70038c, obj(c, 0x40, {0x78: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20))
    return [t, a_val]


S(0x4cf2d0, 'iterator_step_assert', 'thiscall', None, ret='eax', gen=g4cf2d0, note='batch210035')
S(0x511090, 'engine_lookup_store_or_report', 'stdcall', None, ret='eax', gen=g511090, note='batch210035')
S(0x4d0590, 'find_or_create_slot', 'thiscall', None, ret='eax', gen=g4d0590, note='batch210035')
