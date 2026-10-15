"""specs_s43002.py - t4 (Sonnet) batch 43002: 0x585350 (lower bound over 0x48-byte records), 0x6511d0 (flag test through engine slot 0x1b0),
0x4246e0 (conditional vsprintf then slot 0x124; 0x42abee hooked and fills the buffer)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _fl(r):
    k = r.random()
    if k < 0.08:
        return r.choice([0.0, -0.0, float('nan'), float('inf'), float('-inf'), 1.0])
    return r.uniform(-50, 50)


def _g585350(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4, 5, 7, 8, 15, 16, r.randrange(0, 40)])
    arr = rnd(c, 0x48 * 40 + 0x10)
    sortd = r.random() < 0.6
    keys = sorted(r.uniform(-20, 20) for _ in range(40)) if sortd else [_fl(r) for _ in range(40)]
    if r.random() < 0.3:
        keys = [float(r.randrange(-5, 5)) for _ in range(40)]
        if sortd:
            keys.sort()
    for i, kf in enumerate(keys):
        e.w32(arr + 0x48 * i + 0x10, _fb(kf))
    a = rnd(c, 0x20)
    pick = r.random()
    kv = r.choice(keys) if pick < 0.5 else (_fl(r) if pick < 0.9 else float('nan'))
    e.w32(a + 0x10, _fb(kv))
    last = arr + 0x48 * n
    if r.random() < 0.08:
        last += r.choice([1, 5, 0x47, 0x49, 0x50])
    elif r.random() < 0.04:
        last = arr - r.choice([0x48, 0x90, 4])
    return [arr, last, a, _w(c)]


def _g6511d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = 0
    if r.random() < 0.7:
        o = obj(c, 0x20, {0xc: pystub(c, 0, ret=r.choice([0, 1, 0x100, 0x1ff, _w(c)]), this=True)})
    so = sysobj(c, slots={0x1b0: pystub(c, 0, ret=o, this=True)})
    for off in (0x9c7, 0x9c3):
        e.wbytes(so + off, struct.pack('<f', _fl(r)))
    me = rnd(c, 0x80)
    e.w32(me + 0x74, r.choice([0, 1, _w(c)]))
    return [me]


def _g4246e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res: em.ret(eax=_w(c))))
    so = sysobj(c)
    k = struct.unpack('<f', e.rbytes(0x6785d0, 4))[0]
    v = r.choice([k, k, _fl(r), float('nan')])
    e.wbytes(so + 0x9c7, struct.pack('<f', v))
    pat = bytes(r.getrandbits(8) for _ in range(12))

    def fmt(em, kk):
        em.wbytes(em.arg32(0), pat)
    hook_rec(c, 0x42abee, 3, pop=0, stackmark=(0,), deref={2: 1}, side=fmt, ret=_w(c))
    s = pystub(c, 4, pop=0, deref={3: 3})
    ob = obj(c, 0x40, {0x124: s})
    return [_w(c), ob, _w(c), _w(c), _w(c), _w(c)]


S(0x585350, 'GUESS lower bound by float key over 0x48 records', 'fastcall', None, ret='eax', gen=_g585350, note='batch43002')
S(0x6511d0, 'GUESS flag test via engine slot 0x1b0 and two floats', 'thiscall', None, ret='al', gen=_g6511d0, note='batch43002')
S(0x4246e0, 'GUESS conditional vsprintf then slot 0x124', 'cdecl', None, ret=None, gen=_g4246e0, note='batch43002')
