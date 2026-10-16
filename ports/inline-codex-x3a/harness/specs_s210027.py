"""specs_s210027.py - Sonnet-w3a: tree walk, state-switch lookup, string ring buffer, assert-report, float-to-int setters; callees hooked."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g441420(c):
    clear_hooks(c)
    n = 5
    nodes = [rnd(c, 0x80) for _ in range(n)]
    tgt = c.rng.choice(nodes + [0])
    tidx = nodes.index(tgt) if tgt else n
    for i, nd in enumerate(nodes):
        later = nodes[i + 1:]
        c.emu.w32(nd + 0x60, c.rng.choice(later + [0, 0]) if later else 0)
        c.emu.w32(nd + 0x50, c.rng.choice(later + [0] + ([tgt] if (tgt and i < tidx) else [])))
        if c.rng.random() < 0.6:
            c.emu.w32(nd + 0x54, 0)
        else:
            m = rnd(c, 0x60); inner = rnd(c, 0x50)
            _ub(c, inner + 0x23, c.rng.choice([0x100000, 0x200002, 0x300000, 0, _r(c)]))
            c.emu.w32(m + 0xc, inner)
            c.emu.w32(m + 0x50, c.rng.choice(later + [0]) if later else 0)
            c.emu.w32(nd + 0x54, m)
    t = rnd(c, 0x60)
    c.emu.w32(t + 0x4c, c.rng.choice([0, 0, 1]))
    first = nodes[0]
    c.emu.w32(t + 8, first if c.rng.random() < 0.25 else tgt)
    cell = rnd(c, 8); c.emu.w32(cell, first)
    return [t, cell]


def g557ba0(c):
    clear_hooks(c)
    st = rnd(c, 0x20); c.emu.w32(st + 8, c.rng.choice([2, 3, 4, 0, 5]))
    meta = rnd(c, 0x60); c.emu.w32(meta + 0x54, st)
    t = rnd(c, 0x40); c.emu.w32(t + 0x1c, meta)
    a = rnd(c, 0x10); c.emu.w32(a + 4, rnd(c, 0x20)); c.emu.w32(a + 8, rnd(c, 0x20))
    g = rnd(c, 0x2c30); c.emu.w32(0x7003b8, g); _ub(c, g + 0x2c15, rnd(c, 0x20))
    hook_rec(c, 0x5003d0, 1, ret=lambda e, k: rnd(c, 8), this=True)
    hook_rec(c, 0x5002f0, 1, ret=_r(c), this=True)
    hook_rec(c, 0x59d150, 2, ret=c.rng.choice([0, 1, 0x100, 5]), this=True)
    return [t, a]


def g4d4050(c):
    clear_hooks(c)
    t = rnd(c, 0x1100)
    idx = c.rng.choice([0, 1, 5, 0x12, 0x13])
    _ub(c, t + 0x10d3, idx)
    _ub(c, t + idx * 4 + 0xfb7, 0 if c.rng.random() < 0.4 else _r(c))
    L = c.rng.randrange(0, 10)
    s = rnd(c, 0x20); c.emu.wbytes(s, bytes(c.rng.choice([0x41, 0x62, 0xff, 1]) for _ in range(L)) + b'\x00')
    hook_rec(c, 0x634273, 2, ret=_r(c), pop=0)
    hook_rec(c, 0x41e290, 1, ret=lambda e, k: rnd(c, 0x20), pop=0)
    return [t, s]


def g508100(c):
    clear_hooks(c)
    v = c.rng.choice([0, 1, 5, 0xffffffff, 0x80000000, 0x7fffffff, 100])
    x = rnd(c, 8); c.emu.w32(x, v)
    a = rnd(c, 0x10); c.emu.w32(a + 4, rnd(c, 0x20))
    hook_rec(c, 0x5003d0, 1, ret=x, this=True)
    o = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=o, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    w = rnd(c, 0x10)
    if c.rng.random() < 0.4: c.emu.w32(w + 4, 0)
    mem = obj(c, 0x40, {0x20: pystub(c, 0, ret=w, this=True), 0x69c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x1a8)
    t = rnd(c, 0x40); c.emu.w32(t + 0x18, mem)
    mg = rnd(c, 0x60)
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    return [t, a]


def g4e78c0(c):
    clear_hooks(c)
    a = obj(c, 0x40, {0x58: pystub(c, 1, ret=_r(c), this=True), 0x50: pystub(c, 1, ret=_r(c), this=True),
                      0x68: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    t = rnd(c, 0x30)
    for off in (0xd, 0x11):
        f = c.rng.choice([0.0, 1.5, -2.7, 100.9, 1e10, float('nan'), -1e10, 12345.0])
        c.emu.wbytes(t + off, struct.pack('<f', f))
    if c.rng.random() < 0.3: _ub(c, t + 9, 0)
    hook_rec(c, 0x4e7ce0, 1, ret=_r(c), this=True)
    hook_rec(c, 0x4e7c50, 1, ret=_r(c), this=True)
    return [t, a]


S(0x441420, 'tree_walk_next', 'thiscall', None, ret='eax', gen=g441420, note='batch210027')
S(0x557ba0, 'state_switch_lookup_chain', 'thiscall', None, ret='eax', gen=g557ba0, note='batch210027')
S(0x4d4050, 'ring_buffer_store_string', 'thiscall', None, ret='eax', gen=g4d4050, note='batch210027')
S(0x508100, 'positive_or_report', 'thiscall', None, ret='eax', gen=g508100, note='batch210027')
S(0x4e78c0, 'read_fields_float_to_int', 'thiscall', None, ret='eax', gen=g4e78c0, note='batch210027')
