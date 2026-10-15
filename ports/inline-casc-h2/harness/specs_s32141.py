"""specs_s32141.py - h2 (Sonnet) batch 32141: 0x511200, 0x406250. Callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g511200(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    inner = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0, side=_log('log2'))}, nslots=0x30 // 4)
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))}, nslots=0x24 // 4)
    e.w32(0x700390, g)
    s = rnd(c, 0x100)
    sret = r.choice([s, s, 0])
    so = sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=sret)})
    tbl = e.r32(so + 0x9b)
    e.w32(tbl + 0xadc, rnd(c, 0x10))
    hook_rec(c, 0x43eb80, 1, this=True, pop=4, ret=r.getrandbits(32))
    o1 = rnd(c, 0x20)
    o2 = rnd(c, 0x20)
    p0 = rnd(c, 0x10)
    p1 = rnd(c, 0x10)
    e.w32(p1, r.choice([0, 1, 640, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32)]))
    z = rnd(c, 0x10)
    e.wbytes(z + 4, bytes([r.choice([0, 1, 1, 2, 5, 0xff, r.getrandbits(8)])]))

    def pick(emu, k):
        if emu.reg('ecx') == o2:
            return z
        return p0 if emu.arg32(0) == 0 else p1
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=pick)
    e.w32(s + 0x40, r.getrandbits(32))
    arg = rnd(c, 0x20)
    e.w32(arg + 4, o1)
    e.w32(arg + 8, o2)
    return [arg]


def g406250(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([1, 1, 2, 3, 4])
    a3 = r.choice([1, 2, 3, 4])
    a2 = r.choice([0, 0, 1, 2, 5, 7, 11, 16, -1, -2, -3])
    a5 = r.choice([0, 1, 2, 3, 6, 9, 12, 20])
    i0 = int(a2 / a3)       # truncation like idiv
    lim = int((a5 + a2) / a3)
    nrows = 4
    hdr = rnd(c, 0x20)
    e.w32(hdr, n)
    table = rnd(c, 4 * (nrows * n + 4))
    for i in range(nrows * n + 4):
        e.w32(table + 4 * i, _bits(r.choice([r.uniform(-9, 9), r.uniform(-1e3, 1e3), 0.0, 1.0, -1.0])) if r.random() < 0.93 else r.choice([NAN, 0x7f800000]))
    e.w32(hdr + 0xc, table)
    size = max(lim, 0) + 8
    arrs = []
    for _ in range(a3):
        base = rnd(c, 4 * (size + 8))
        for i in range(size + 8):
            e.w32(base + 4 * i, _bits(r.choice([r.uniform(-9, 9), 0.0, 1e30, 3.0, -3.0])) if r.random() < 0.95 else r.choice([NAN, 0x7f800000]))
        arrs.append(base + 16)      # slack of four floats before element 0
    ptrs = rnd(c, 4 * a3)
    for i, a in enumerate(arrs):
        e.w32(ptrs + 4 * i, a)
    stop = r.choice([-1, 99, 99, 99, 99, r.randrange(0, 4)])
    idxs = [r.randrange(0, nrows) for _ in range(12)]
    hook_rec(c, 0x405f20, 2, pop=0, ret=lambda emu, k: (0xffffffff if k == stop else idxs[min(k, 11)]), side=_log('f20'))
    return [hdr, ptrs, a2 & 0xffffffff, a3, r.getrandbits(32), a5]


S(0x511200, 'GUESS register id and stamp entry', 'stdcall', None, ret=None, gen=g511200, nan_heap=True, note='batch32141')
S(0x406250, 'GUESS accumulate rows into channel arrays', 'cdecl', None, ret='eax', gen=g406250, nan_heap=True, note='batch32141')
