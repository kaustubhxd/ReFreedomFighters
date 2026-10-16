"""specs_s210020.py - Sonnet-w3a: array membership, bit-buffer flush, chain iterator init, release loop, engine flag check; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g5fb550(c):
    clear_hooks(c)
    n = c.rng.choice([0, 1, 2, 3, 5])
    arr = rnd(c, 0x20)
    t = rnd(c, 0x40); c.emu.w32(t + 0x18, arr); c.emu.w32(t + 0x20, n)
    a = c.emu.r32(arr + 4 * c.rng.randrange(0, 5)) if (n and c.rng.random() < 0.5) else _r(c)
    return [t, a]


def g630120(c):
    clear_hooks(c)
    a = rnd(c, 0x16c0)
    c.emu.w32(a + 8, rnd(c, 0x40)); c.emu.w32(a + 0x14, c.rng.randrange(0, 8))
    n = c.rng.choice([0x10, 0x10, 8, 9, 15, 0, 3, 7, 0xffffffff, 0x80000000, 0x11, 0x20, _r(c)])
    c.emu.w32(a + 0x16b4, n)
    return [a]


def g440ce0(c):
    clear_hooks(c)
    k = c.rng.choice([0, 1, 2, 3, 4])
    nodes = [rnd(c, 0x40) for _ in range(k)]
    for i, nd in enumerate(nodes):
        c.emu.wbytes(nd + 8, bytes([c.rng.choice([0, 1, 1, 1, 2, 3, 0x80, 0xff])]))
        c.emu.w32(nd + 0xc, nodes[i + 1] if (i + 1 < k and c.rng.random() < 0.85) else 0)
    return [rnd(c, 0x10), nodes[0] if nodes else 0]


def g4dae60(c):
    clear_hooks(c)
    t = rnd(c, 0x80)
    c.emu.wbytes(t + 0x5c, (0 if c.rng.random() < 0.2 else c.rng.randrange(1, 0x10000)).to_bytes(2, 'little'))
    o = 0 if c.rng.random() < 0.2 else rnd(c, 0x40)
    cnt = c.rng.choice([0, 1, 2, 3])
    if o:
        c.emu.wbytes(o + 0x1c, bytes([1 if cnt else 0]))

        def side(emu, k):
            if k + 1 >= cnt:
                emu.wbytes(o + 0x1c, b'\x00')
        hook_rec(c, 0x4dc1e0, 1, ret=_r(c), this=True, side=side)
    else:
        hook_rec(c, 0x4dc1e0, 1, ret=_r(c), this=True)
    hook_rec(c, 0x4db580, 1, ret=_r(c), this=True)
    hd = obj(c, 0x40, {0x5c: pystub(c, 1, ret=o, this=True), 0x54: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    m = rnd(c, 0x20); c.emu.w32(m + 8, hd)
    _eng(c, m)
    return [t]


def g56a7e0(c):
    clear_hooks(c)
    t = rnd(c, 0x1d0)
    _ub(c, t + 0x1c5, 4 if c.rng.random() < 0.7 else _r(c))
    o = 0 if c.rng.random() < 0.2 else obj(c, 0x40, {0x1e0: pystub(c, 1, ret=c.rng.choice([0, 1, 0x100, _r(c)]), this=True),
                                                   0x310: pystub(c, 0, ret=_r(c), this=True)}, nslots=0xd0)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=o, this=True)}, nslots=0x20))
    hook_rec(c, 0x56ad00, 1, ret=_r(c), this=True)
    return [t, _r(c), _r(c)]


S(0x5fb550, 'array_contains', 'thiscall', None, ret='al', gen=g5fb550, note='batch210020')
S(0x630120, 'flush_bit_buffer', 'cdecl', None, ret='eax', gen=g630120, note='batch210020')
S(0x440ce0, 'chain_iterator_init', 'thiscall', None, ret='eax', gen=g440ce0, note='batch210020')
S(0x4dae60, 'release_loop_slot54', 'thiscall', None, ret=None, gen=g4dae60, note='batch210020')
S(0x56a7e0, 'check_flag_slot310', 'thiscall', None, ret='al', gen=g56a7e0, note='batch210020')
