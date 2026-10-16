"""specs_s210036.py - Sonnet-w3a: tag-checked reader, string lookup copy, vector copy chain; callees hooked."""
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


def g4e0fd0(c):
    clear_hooks(c)
    _assert_hook(c)
    buf = rnd(c, 0x60)
    c.emu.wbytes(buf, bytes([c.rng.choice([9, 9, 0x49, 0xff, 0x01, 0x3f])]))
    for i in range(6): _ub(c, buf + 5 + 4 * i, 0 if c.rng.random() < 0.3 else _r(c))
    t = rnd(c, 0x20); c.emu.w32(t + 8, buf)
    hook_rec(c, 0x4e1590, 0, ret=c.rng.choice([4, 8, 12, 16, 20, 5]), this=True)
    g = obj(c, 0x40, {0x24: pystub(c, 2, ret=_r(c), pop=0)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    out = obj(c, 0x40, {4: pystub(c, 1, ret=_r(c), this=True)}, nslots=8)
    return [t, out]


def g565190(c):
    clear_hooks(c)
    s = rnd(c, 0x20)
    L = c.rng.randrange(0, 8)
    c.emu.wbytes(s, bytes(c.rng.choice([0x41, 0x62, 0xff]) for _ in range(L)) + b'\x00')
    m = obj(c, 0x40, {0: pystub(c, 2, ret=s, this=True)}, nslots=4)
    mg = rnd(c, 0xb00); c.emu.w32(mg + 0xae4, m)
    w = obj(c, 0x40, {0x198: pystub(c, 4, ret=_r(c), pop=0)}, nslots=0x70)
    eng = obj(c, 0x200, {0x190: pystub(c, 0, ret=w, this=True)}, nslots=0x70)
    _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    mode = c.rng.choice(['none', 'c', 'd', 'cd', 'b0'])
    cv = rnd(c, 8) if mode in ('c', 'cd') else 0
    dv = _r(c) | 1 if mode in ('d', 'cd') else 0
    b = 0 if mode == 'b0' else rnd(c, 8)
    return [rnd(c, 0x20), b, cv, dv]


def g51c140(c):
    clear_hooks(c)
    hook_rec(c, 0x512590, 0, ret=_r(c), this=True)
    eo = 0 if c.rng.random() < 0.3 else obj(c, 0x40, {0x60: pystub(c, 2, ret=lambda e, k: c.rng.getrandbits(32), this=True)}, nslots=0x20)
    eng = rnd(c, 0x1b00); _ub(c, eng + 0x1a9f, eo)
    c.emu.w32(0x70039c, eng)
    emb = obj(c, 0x40, {4: pystub(c, 2, ret=_r(c), this=True)}, nslots=8)
    t = obj(c, 0x380, {0x80: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x40)
    c.emu.w32(t + 0x34e, c.emu.r32(emb))
    _ub(c, t + 0x12f, 0 if c.rng.random() < 0.3 else _r(c))
    return [t]


S(0x4e0fd0, 'tag_checked_reader_9', 'thiscall', None, ret='eax', gen=g4e0fd0, note='batch210036')
S(0x565190, 'string_lookup_copy', 'stdcall', None, ret=None, gen=g565190, note='batch210036')
S(0x51c140, 'init_vectors_copy_chain', 'thiscall', None, ret='eax', gen=g51c140, note='batch210036')
