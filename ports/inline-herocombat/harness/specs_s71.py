"""specs_s71.py - inline session batch 71: sewer entry. ZFFHeroMovementOpenSewer TerminateControl, WantControl,
GotControl, Move and GetActiveAnim, and ZFFActionClimbSewer::Execute. RestoreItem, SetTempItem (with GetItem on an
empty inventory list), SetUseAction, ActivateMenu, ProgressValue, the meter switch, createmat, mmtmul, vaddscalar,
mpul and GetStartingSewerLid (stopped at its first checks) run as exe code. The level's sewer list (9-byte records at
[0x7003b8]+0xc6d) holds 0 to 4 lids near the hero; the render manager's slot 0x58 maps their handles to recorder lid
objects. CharismaAddExperience is not reached (the level name never has '1' at +0x4a)."""
import struct
from pilot import S, F
import specs_s53 as k53
import specs_s60 as k60
import specs_s69 as k69
import specs_s70 as k70

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_seq, _fv = k60._seq, k60._fv
P = lambda v: struct.pack('<I', v & 0xffffffff)
XYZ = [(0, 'd'), (4, 'd'), (8, 'd')]
M9 = [(4 * i, 'd') for i in range(9)]


def _mat(c):
    r = c.rng
    return _fv(c, [r.uniform(-1, 1) for _ in range(9)])


def _vec(c, base, k):
    r = c.rng
    return _fv(c, [b + r.uniform(-k, k) for b in base])


def _getter(c, base, k):
    """slot 0x80 (mat*, pos*): fills a random frame and a position near base."""
    return _stub(c, 2, skip=(0, 1), fills=((0, _mat(c), 9), (1, _vec(c, base, k), 3)))


def _world(c, hero_pos, extra=()):
    """Level, render manager, sewer list, menu objects. Returns (rm, recs, lids)."""
    r = c.rng
    n = r.choice((0, 1, 1, 2, 3, 4))
    L = _rnd(c, 0x2c20)
    c.emu.w32(L + 0xc69, n)
    lc = _rnd(c, 0x1100)
    c.emu.wbytes(lc + 0x4a, bytes([r.choice((0x30, 0x32, 0x41))]))
    c.emu.w32(L + 0x2c15, lc)
    c.emu.w32(0x7003b8, L)
    vv = r.getrandbits(32)
    x = _rnd(c, 0x100)
    wvt = c.emu.alloc(0x20, 4)
    c.emu.w32(wvt + 0x14, _stub(c, 0, ret=r.choice((0, 0, 1))))
    c.emu.w32(x + 0xcb, wvt)
    menu = _obj(c, 0x20, {0x2c4: _stub(c, 0, ret=x)})
    pairs, recs, lids = [(vv, menu)] + list(extra), [], []
    for i in range(n):
        par = _obj(c, 0x20, {0x80: _getter(c, hero_pos, 300), 0x7c: _stub(c, 2, skip=(0, 1), copy=(0, M9))})
        lid = _obj(c, 0x200, {0x80: _getter(c, hero_pos, 260), 0x7c: _stub(c, 2, skip=(0, 1), copy=(0, M9)),
                              0x20: _stub(c, 0, ret=par), 0x128: _stub(c, 3)})
        sew = _rnd(c, 0x60)
        c.emu.w32(sew + 0x44, _obj(c, 0x140, {0x12c: _stub(c, 3), 0x130: _stub(c, 3)}))
        h = r.getrandbits(32)
        rec = L + 0xc6d + 9 * i
        c.emu.w32(rec, sew)
        c.emu.w32(rec + 4, h)
        c.emu.wbytes(rec + 8, bytes([r.choice((0, 1))]))
        pairs.append((h, lid))
        recs.append(rec)
        lids.append(lid)
    db = _obj(c, 0x10, {0x88: k70._dbstub(c, [r.choice((0, r.getrandbits(32))), vv])})
    rm = _obj(c, 0x120, {0x58: k60._map(c, pairs, 0), 0x114: _seq(c, 4, [r.getrandbits(32), r.getrandbits(32)]),
                         0x138: _stub(c, 0, ret=db), 0xb4: _stub(c, 1),
                         0x4c: _seq(c, 1, [r.getrandbits(32), r.getrandbits(32)])})
    g = k70._sys(c, rm)
    c.emu.w32(g + 0x1a9f, _obj(c, 0x140, {0x138: _stub(c, 1)}) if r.random() < 0.8 else 0)
    c.emu.w32(0x7003b0, _stub(c, 0))
    return rm, recs, lids


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _inventory(c, h, pairs):
    """Inventory info for types 1 and 2 (and a random one) and an inventory list holding their items, so the type
    of a temporary item is seen (GetItem). Returns (inventory object, items); the item handles go into pairs."""
    r = c.rng
    vals = [0x1000, 0x2000, 0x3000]
    types = [1, 2, r.randint(0, 5)]
    r.shuffle(types)
    for i in range(3):
        e = _rnd(c, 0x20)
        c.emu.w32(e, vals[i])
        c.emu.w32(e + 0x10, types[i])
        c.emu.w32(h + 0x95f + 4 * i, e)
    c.emu.w32(h + 0x95b, 3)
    hs, items = [], []
    for v in vals:
        it = _obj(c, 0x20, {0x2e8: _code(c, b'\x8b\x41\x08\xc3')})
        c.emu.w32(it + 8, v)
        hh = r.getrandbits(32) | 1
        pairs.append((hh, it))
        hs.append(hh)
        items.append(it)
    tab = c.emu.alloc(4 * (len(hs) + 2), 4)
    for i, hh in enumerate(hs):
        c.emu.w32(tab + 4 * (i + 1), hh)
    lst = _obj(c, 0x10, {0x48: _code(c, b'\x8b\x44\x24\x04\xc7\x00' + P(len(hs) + 1) + b'\xc2\x04\x00'),
                         0x58: _code(c, b'\x8b\x4c\x24\x04\x8b\x01\x85\xc0\x74\x0a\x48\x89\x01\x8b\x04\x85' + P(tab)
                                     + b'\xc2\x04\x00')})
    inv = _obj(c, 0x10, {0xa0: _stub(c, 0, ret=lst)})
    return inv, items


def _exact_start(c, s, anim, thrs):
    """Start time (+0x54f) so that the elapsed time is exactly a frame threshold of anim (rate dividing 1024)."""
    r = c.rng
    rate = r.choice((16, 32, 64))
    c.emu.w32(anim + 0x6c, rate)
    now = c.emu.r32(c.emu.r32(0x70039c) + 0x40)
    now = now if now < 1 << 31 else now - (1 << 32)
    d = r.choice(thrs) * 1024 // rate
    c.emu.wf32(s + 0x54f, (now - d) / 1024.0)


def _hero(c, hero_pos, pairs=None):
    r = c.rng
    hg = _obj(c, 0x80, {0x84: _stub(c, 1, skip=(0,), fills=((0, _vec(c, hero_pos, 5), 3),)),
                        0x74: _stub(c, 2, skip=(0, 1), copy=(0, M9))})
    h = _obj(c, 0xa00, {0x59c: _stub(c, 2, skip=(0, 1), fills=((0, _mat(c), 9), (1, _fv(c, hero_pos), 3))),
                        0x438: _stub(c, 0, ret=r.choice((0, 0, 0, 0, 1, 0x100))),
                        0x3a0: _stub(c, 2, skip=(0, 1), ret=r.getrandbits(32)), 0x390: _stub(c, 1),
                        0x20: _stub(c, 0, ret=hg), 0x3dc: _stub(c, 0), 0x480: _stub(c, 1),
                        0x504: _stub(c, 0, ret=r.choice((0, r.getrandbits(32)))), 0x228: _stub(c, 5)})
    c.emu.w32(h + 0x852, _rnd(c, 0x2300))
    c.emu.w32(h + 0x95b, 0)
    if pairs is not None:
        inv, items = _inventory(c, h, pairs)
        c.emu.w32(c.emu.r32(h) + 0x504, _stub(c, 0, ret=r.choice([0, r.getrandbits(32)] + items)))
        vt = c.emu.r32(h)
        nv = c.emu.alloc(0x600, 4)
        c.emu.wbytes(nv, c.emu.rbytes(vt, 0x5a0))
        c.emu.w32(nv + 0x464, _stub(c, 0, ret=inv))
        c.emu.w32(h, nv)
    c.emu.w32(h + 0x832, 0)
    c.emu.w32(h + 0x836, r.getrandbits(32))
    c.emu.wbytes(h + 0x9f5, bytes([r.choice((0, 1, 1, 1))]))
    c.emu.w32(h + 0x9d3, r.choice((10, 12, 12, 10, 0, r.getrandbits(32))))
    c.emu.wbytes(h + 0x66c, bytes([r.choice((0, 1, 1))]))
    c.emu.wf32(h + 0x9db, r.choice((1e9, 100.0, 0.0)))
    c.emu.wf32(h + 0x9e3, r.choice((0.0, 0.0, r.uniform(1, 100))))
    return h


def _anim(c):
    r = c.rng
    a = _rnd(c, 0x80)
    c.emu.w32(a + 0x60, r.choice((0, 0, 1)))
    c.emu.w32(a + 0x64, r.choice((150, 170, 200, r.randint(100, 260))))
    c.emu.w32(a + 0x6c, r.choice((25, 30, r.randint(1, 60))))
    return a


def _self(c, h, recs):
    r = c.rng
    s = _obj(c, 0x600, {0x48: _stub(c, 5, ret=r.choice((0, 1, 0x100)))})
    c.emu.w32(s + 0x36d, h)
    c.emu.wbytes(s + 0x54c, bytes([r.choice((0, 1, 1)), r.choice((0, 0, 1))]))
    now = c.emu.r32(c.emu.r32(0x70039c) + 0x40)
    nows = (now if now < 1 << 31 else now - (1 << 32)) / 1024.0
    c.emu.wf32(s + 0x54f, r.choice((nows, nows - r.uniform(0, 0.4), nows - r.uniform(0, 10), nows - r.uniform(5, 9))))
    c.emu.w32(s + 0x553, _anim(c) if r.random() < 0.9 else 0)
    c.emu.w32(s + 0x557, r.choice(recs) if recs else 0)
    c.emu.wbytes(s + 0x55b, b''.join(struct.pack('<f', r.uniform(-500, 500)) for _ in range(6)))
    c.emu.wbytes(s + 0x573, b''.join(struct.pack('<f', r.uniform(-1, 1)) for _ in range(18)))
    return s


def _setup(c, need_rec=False):
    r = c.rng
    hp = [r.uniform(-2000, 2000) for _ in range(3)]
    if r.random() < 0.03:
        hp[r.randint(0, 2)] = float('nan')
    pairs = []
    h = _hero(c, hp, pairs)
    while True:
        rm, recs, lids = _world(c, hp, pairs)
        if recs or not need_rec:
            break
    s = _self(c, h, recs)
    if r.random() < 0.3 and c.emu.r32(s + 0x553):
        a = c.emu.r32(s + 0x553)
        _exact_start(c, s, a, (104, 139, c.emu.r32(a + 0x64) - c.emu.r32(a + 0x60) + 1))
    return s, hp


def _term(c):
    s, _ = _setup(c)
    c.emu.mu.ctl_flush_tb()
    return [s, c.rng.choice((0, 1, 0x100))]


def _want(c):
    s, hp = _setup(c)
    pos = _fv(c, hp)
    c.emu.mu.ctl_flush_tb()
    return [s, _vec(c, hp, 1), pos, _vec(c, hp, 1)]


def _got(c):
    s, _ = _setup(c, need_rec=True)
    c.emu.mu.ctl_flush_tb()
    return [s]


def _move(c):
    r = c.rng
    s, hp = _setup(c)
    m = _mat(c) if r.random() < 0.5 else _fv(c, [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0])
    k = r.random()
    if k < 0.3:   # the walk-to frame equal to the start frame (mpul's blend path rather than its slerp path)
        c.emu.wbytes(s + 0x597, c.emu.rbytes(s + 0x573, 36))
    elif k < 0.5:   # both frames orthonormal, so the rows' dot products are positive and the blend path runs
        ident = b''.join(struct.pack('<f', v) for v in (1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0))
        c.emu.wbytes(s + 0x573, ident)
        c.emu.wbytes(s + 0x597, b''.join(struct.pack('<f', v + r.uniform(-0.3, 0.3)) for v in
                                         (1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0)))
    outm, outp, outv = _rnd(c, 0x30), _rnd(c, 0x10), _rnd(c, 0x10)
    c.emu.mu.ctl_flush_tb()
    return [s, m, _vec(c, hp, 50), outm, outp, outv]


def _gaa(c):
    s, _ = _setup(c, need_rec=True)
    out = _rnd(c, 4)
    c.emu.mu.ctl_flush_tb()
    return [s, out, 0, 0, 0, 0]


def _climb(c):
    r = c.rng
    hp = [r.uniform(-2000, 2000) for _ in range(3)]
    _world(c, hp)
    h = _hero(c, hp)
    lc = c.emu.r32(c.emu.r32(0x7003b8) + 0x2c15)
    b = _obj(c, 0x300, {0x25c: _seq(c, 2, [r.choice((0, _obj(c, 0x40, {0x80: _getter(c, hp, 100)}))),
                                           r.choice((0, _obj(c, 0x40, {0x80: _getter(c, hp, 100)})))])})
    a = _obj(c, 0x40, {0x20: _stub(c, 0, ret=b)})
    lid = _obj(c, 0x40, {0x20: _stub(c, 0, ret=a), 0x80: _getter(c, hp, 100)})
    c.emu.wbytes(lc + 0x103f, bytes([r.choice((0, 0, 0, 1))]))
    c.emu.w32(lc + 0x1050, lid)
    if r.random() < 0.1:
        c.emu.w32(c.emu.r32(0x7003b8) + 0x2c15, 0)
    s = _rnd(c, 0x20)
    c.emu.w32(s + 8, h)
    c.emu.w32(s + 0xc, r.choice((0, r.getrandbits(32), r.getrandbits(32))))
    c.emu.mu.ctl_flush_tb()
    return [s]


S(0x5e7420, 'ZFFHeroMovementOpenSewer::TerminateControl', 'thiscall', None, ret='al', gen=_term, note='batch71')
S(0x5e88e0, 'ZFFHeroMovementOpenSewer::WantControl', 'thiscall', None, ret='al', gen=_want, note='batch71')
S(0x5e5600, 'ZFFHeroMovementOpenSewer::GotControl', 'thiscall', None, ret=None, gen=_got, note='batch71')
S(0x5e6eb0, 'ZFFHeroMovementOpenSewer::Move', 'thiscall', None, ret=None, gen=_move, note='batch71; mpul as exe code')
S(0x5e3220, 'ZFFHeroMovementOpenSewer::GetActiveAnim', 'thiscall', None, ret='st0', gen=_gaa, note='batch71')
S(0x5e0100, 'ZFFActionClimbSewer::Execute', 'thiscall', None, ret='al', gen=_climb, note='batch71')
