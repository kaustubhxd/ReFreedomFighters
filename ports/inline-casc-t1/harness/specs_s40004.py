"""specs_s40004. 0x480020: assert hook set, this slot 0x48 (via the real thunk 0x45d5b0), src slot 0x1e0 returns al (0 / 1 / dirty upper bytes). 0x5d5fc0: head/tail ints (zero, equal, negative), sys float +0x48 gives cap -5..1000, slots 0xbc/0x250 recorded.
0x5162e0: p floats, hooked 0x516130 (st0), the real small callees 0x5243f0/0x5243d0/0x524980 run on random blocks (unaligned float at +0x35). 0x566b20: sys int +0x40 around the limit float, counts and slots, hooked 0x5668d0 (st0, includes NaN and big values).
0x4b8a30: hooked 0x4e5e40/0x4e5e80/0x4e6330, stream pointer to a kind byte (0xff, 2, 0x42, others), slot 0x14 returns 0/non-zero, engine table slot 0x4c, slot 4. 0x5de4c0: slot 0x10 buffers logged, ret al."""
import struct
from pilot import S, EDGE_F, F
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, hook_rec


def _fb(v):
    try:
        return struct.unpack('<I', struct.pack('<f', v))[0]
    except OverflowError:
        return 0x7f800000 if v > 0 else 0xff800000


def _rf(r):
    k = r.random()
    if k < 0.15:
        return _fb(r.choice(EDGE_F))
    if k < 0.2:
        return r.getrandbits(32)
    return _fb(r.uniform(-1000, 1000))


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g480020(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    me = obj(c, 0x100, {0x48: pystub(c, 1, this=True)}, nslots=0x4c // 4)
    src = obj(c, 0x100, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 0x100, 0x1234500, 0xff, r.getrandbits(32)]), this=True)}, nslots=0x1e4 // 4)
    return [me, src]


def _g5d5fc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    cap = r.choice([-5, 0, 3, 10, 32, 1000])
    e.w32(so + 0x48, _fb(cap / 2000.0) if r.random() < 0.9 else _rf(r))
    o = obj(c, 0x20, {0xbc: pystub(c, 1, this=True), 0x250: pystub(c, 1, this=True)}, nslots=0x254 // 4)
    me = rnd(c, 0x80)
    a = r.choice([0, 0, 1, 5, 100, -3 & 0xffffffff, r.randrange(0, 500)])
    k = r.random()
    if k < 0.15:
        b = a
    elif k < 0.3:
        b = 0
    elif k < 0.45:
        b = (a - r.choice([1, 5, 40, 2000])) & 0xffffffff
    else:
        b = (a + r.choice([1, 5, 40, 2000, 100000])) & 0xffffffff
    e.w32(me + 0x4c, a & 0xffffffff)
    e.w32(me + 0x50, b)
    e.w32(me + 0x44, o)
    return [me]


def _g5162e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x516130, 2, this=True, st0=lambda em, k: r.choice([0.0, 1.0, -2.5, 123.25, r.uniform(-50, 50)]))
    me = rnd(c, 0x100)
    p = rnd(c, 0x10)
    for off in (0, 4, 8):
        e.w32(p + off, _rf(r))
    e.wbytes(me + 0x35, struct.pack('<I', _rf(r)))
    return [me, p]


def _g566b20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    t = r.choice([0, 100, 1000, 5000, r.randrange(0, 20000)])
    e.w32(so + 0x40, t)
    delta = r.choice([0, 0, -1, 1, -100, 100, 5000])
    me = rnd(c, 0xa40)
    e.w32(me + 0x1ea, _fb((t + delta) / 1024.0) if r.random() < 0.9 else _rf(r))
    cnt = r.randrange(0, 9)
    i = r.choice([0, 1, cnt, cnt - 1, cnt + 1, r.randrange(0, 9)])
    e.w32(me + 0x1be, cnt)
    e.w32(me + 0x9f8, i & 0xffffffff)
    if r.random() < 0.15:
        e.w32(me + 0x19e + 4 * (i % 9), 0)
    vals = [0.0, 1.0, -1.0, 0.5, 3.0, 1e9, float('nan'), r.uniform(-4, 4)]
    hook_rec(c, 0x5668d0, 3, this=True, st0=lambda em, k: r.choice(vals))
    return [me]


def _g4b8a30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e5e40, 0, this=True, ret=lambda em, k: r.getrandbits(32))
    fv = [0.0, 1.5, -3.25, r.uniform(-100, 100)]
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: r.choice(fv))
    hook_rec(c, 0x4e6330, 1, this=True)
    buf = rnd(c, 0x10)
    e.wbytes(buf, bytes([r.choice([0xff, 2, 0x42, 0x82, 0xc2, 0x3f, 0, r.getrandbits(8)])]))
    s = rnd(c, 0x20)
    e.w32(s, buf)
    q = obj(c, 0x20, {0x14: pystub(c, 0, ret=r.choice([0, 0, 1, r.getrandbits(32)]), this=True), 4: pystub(c, 1, this=True)}, nslots=0x18 // 4)
    so = sysobj(c, table_slots={0x4c: pystub(c, 1, ret=r.getrandbits(32), this=True)}, table_size=0x20)
    me = rnd(c, 0x80)
    e.w32(me + 0x4c, q)
    return [me, s]


def _g5de4c0(c):
    clear_hooks(c)
    r = c.rng

    def logbuf(em, k):
        p, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('buf', bytes(em.rbytes(p, n))))
    o = obj(c, 0x20, {0x10: pystub(c, 2, this=True, side=logbuf), 0x64: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True)}, nslots=0x68 // 4)
    me = rnd(c, 0x140)
    return [me, o]


S(0x480020, 'GUESS copy block when accepted', 'thiscall', None, ret=None, gen=_g480020, note='batch40004')
S(0x5d5fc0, 'GUESS step toward target value', 'thiscall', None, ret=None, gen=_g5d5fc0, note='batch40004')
S(0x5162e0, 'GUESS set vector and derived values', 'thiscall', None, ret=None, gen=_g5162e0, note='batch40004')
S(0x566b20, 'GUESS advance timed entry', 'thiscall', None, ret=None, gen=_g566b20, note='batch40004')
S(0x4b8a30, 'GUESS read record from stream', 'thiscall', None, ret=None, gen=_g4b8a30, note='batch40004')
S(0x5de4c0, 'GUESS write record to stream', 'thiscall', None, ret='al', gen=_g5de4c0, note='batch40004')
