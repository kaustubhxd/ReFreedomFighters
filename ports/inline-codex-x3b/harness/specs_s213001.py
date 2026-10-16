"""specs_s213001.py - batch 213001: jump-table functions (setter, lookup dispatch, class-table scanners), Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _sel(c):
    r = c.rng
    return r.randint(0xa, 0x12) if r.random() < 0.85 else r.getrandbits(32)


def g5af2a0(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x40)
    val = r.choice([0, 1, r.getrandbits(32), r.getrandbits(32)])
    return [o, _sel(c), val]


def g5afc70(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x40)
    ret = r.randint(0, 0x16) if r.random() < 0.9 else r.getrandbits(32)
    blk = rnd(c, 0x20)
    hook_rec(c, 0x5aeff0, 1, ret=ret, this=True)
    hook_rec(c, 0x5af130, 1, ret=blk, this=True)
    return [o, r.getrandbits(32)]


def _classtab(c, hot, nhot=0.6):
    r = c.rng
    base = rnd(c, 0x4c + 0x100 + 4)
    tab = bytes((r.choice(hot) if r.random() < nhot else r.getrandbits(8)) for _ in range(256))
    c.emu.wbytes(base + 0x4c, tab)
    return base, tab


def g622d20(c):
    clear_hooks(c)
    r = c.rng
    base, tab = _classtab(c, [9, 0xa, 0x15, 0x15, 0x8, 0xb, 0x14, 0x16])
    n = 0x80
    buf = bytearray(r.getrandbits(8) for _ in range(n))
    for i in range(0, n - 4, 2):
        if r.random() < 0.8:
            buf[i] = 0
    for i in range(n - 4, n):
        buf[i] = 0xff   # stops the scan (nonzero first byte)
    p = rnd(c, n + 4)
    c.emu.wbytes(p, bytes(buf))
    return [base, p]


def g6228e0(c):
    clear_hooks(c)
    r = c.rng
    base, tab = _classtab(c, [5, 6, 7, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1d, 8, 0x14], 0.7)
    n = 0x200
    buf = bytearray(r.getrandbits(8) for _ in range(n))
    stop = next((b for b in range(256) if tab[b] - 5 > 0x18 or tab[b] < 5), None)
    if stop is None:
        stop = 0
        c.emu.wbytes(base + 0x4c, bytes([0x30]) + tab[1:])
    for i in range(n - 8, n):
        buf[i] = stop
    p = rnd(c, n + 8)
    c.emu.wbytes(p, bytes(buf))
    return [base, p]


S(0x5af2a0, 'set_field_by_sel', 'thiscall', None, ret='eax', gen=g5af2a0)
S(0x5afc70, 'lookup_dispatch', 'thiscall', None, ret='eax', gen=g5afc70)
S(0x622d20, 'skip_class_pairs', 'cdecl', None, ret='eax', gen=g622d20)
S(0x6228e0, 'scan_class_run', 'cdecl', None, ret='eax', gen=g6228e0)
