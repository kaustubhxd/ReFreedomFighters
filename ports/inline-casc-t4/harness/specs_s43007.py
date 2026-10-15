"""specs_s43007.py - t4 (Sonnet) batch 43007. 0x478f90: record array with float keys; 0x527ee0: callees 0x528260 / 0x5291f0 / 0x527f80 hooked, slot 0x80 stub;
0x5c3000: 0x5c3560 hooked, slots 0x68 / 0x64 stubs."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _fl(r):
    k = r.random()
    if k < 0.06:
        return r.choice([0.0, -0.0, float('nan'), float('inf'), float('-inf')])
    if k < 0.2:
        return r.uniform(-1e5, 1e5)
    return r.uniform(-20, 20)


def _g478f90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = r.choice([0, 1, 2, 3, 5, 8])
    arr = rnd(c, 16 * 12 + 64)
    base = arr + 32
    keys = sorted(r.uniform(-10, 10) for _ in range(10)) if r.random() < 0.7 else [_fl(r) for _ in range(10)]
    if r.random() < 0.3:
        keys = [float(r.randrange(-4, 4)) for _ in range(10)]
        keys.sort()
    for i, kf in enumerate(keys):
        e.w32(base + 16 * i, _fb(kf))
    me = rnd(c, 0x20)
    e.w32(me, r.choice([0, 1, 2, max(cnt - 1, 0), cnt, r.randrange(0, 9), -1]) & 0xffffffff)
    e.w32(me + 8, cnt)
    e.w32(me + 0xc, base)
    k = r.choice([r.choice(keys), _fl(r), r.uniform(-12, 12), float('nan')])
    return [me, F(k)]


def _g527ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x528260, 1, this=True)
    hook_rec(c, 0x5291f0, 1, this=True)
    hook_rec(c, 0x527f80, 0, this=True)
    so = sysobj(c)
    e.w32(so + 0x40, r.choice([0, 1, 1000, 0x7fffffff, 0x80000000, _w(c), r.randrange(0, 100000)]))
    a = obj(c, 0x20, {0x80: pystub(c, 2, this=True, stackmark=(1,))})
    me = rnd(c, 0x2200)
    return [me, a, F(_fl(r)), _w(c), _w(c)]


def _g5c3000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5c3560, 2, this=True)
    so = sysobj(c)
    e.w32(so + 0x40, r.choice([0, 1, 1000, 0x7fffffff, 0x80000000, _w(c), r.randrange(0, 100000)]))
    me = obj(c, 0x140, {0x68: pystub(c, 2, this=True), 0x64: pystub(c, 1, this=True)})
    e.wbytes(me + 0xf4, bytes([r.choice([0, 1, 2, 3, 0xff, r.getrandbits(8)])]))
    return [me]


S(0x478f90, 'GUESS seek index by float key in sorted records', 'thiscall', None, ret='eax', gen=_g478f90, note='batch43007')
S(0x527ee0, 'GUESS initialise object from owner and parameters', 'thiscall', None, ret=None, gen=_g527ee0, note='batch43007')
S(0x5c3000, 'GUESS reset state by mode byte', 'thiscall', None, ret=None, gen=_g5c3000, note='batch43007')
