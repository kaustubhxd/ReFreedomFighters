"""specs_s74.py - inline session batch 74: planting C4. ZFFHeroMovementPlaceC4 WantControl, GotControl and
GetActiveAnim, ZFFHERO::SendFollowersToSafepoints, ConvPtr, ZBaseGeom::GetOwner and ZGameOSD::MessageAdd. GetItem,
SetTempItem, RestoreItem, SetUseAction, ProgressValue, the meter switch, GetGameOSD, the vector helpers and the batch's
own helpers run as exe code. Two OSD callees owned by other threads are patched per run with a jump to a recorder that
logs ecx and the args (the image is marked dirty so the next run restores it): ZGameOSD::PlaySound (0x59a5e0) and
ZOnScreenDisplay::MessageAdd (0x5aaa30). The object manager at [0x70038c] answers ConvPtr (slot 0x20, the converter
at +8 with its range +0xc..+0x10, the id writer slot 0xac)."""
import struct
from pilot import S, F
import specs_s53 as k53
import specs_s60 as k60
import specs_s70 as k70
import specs_s71 as k71
import specs_s72 as k72
import specs_s73 as k73

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_seq, _fv = k60._seq, k60._fv
_mat, _vec, _code, _copy2 = k71._mat, k71._vec, k72._code, k72._copy2
_patch, _iter, _resp, _exact_at, _ecx = k73._patch, k73._iter, k73._resp, k73._exact_at, k73._ecx
P = lambda v: struct.pack('<I', v & 0xffffffff)
Q3 = [(0, 'd'), (4, 'd'), (8, 'd')]
NAN = float('nan')


def _msg2(c, vals):
    """slot 0x130 (geom, cmd, data*), ret 0xc: logs cmd and geom per call (eight calls); when data is not null, writes
    the two dwords vals[call & 1] through it."""
    tab = c.emu.alloc(16, 4)
    c.emu.wbytes(tab, b''.join(P(v) for v in vals[0] + vals[1]))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(64, 4)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x07\x8b\x54\x24\x08\x89\x14\xc5' + P(log)
    code += b'\x8b\x54\x24\x04\x89\x14\xc5' + P(log + 4)
    code += b'\x8b\x54\x24\x0c\x85\xd2\x74\x15\xa1' + P(cnt) + b'\x83\xe0\x01'
    code += b'\x8b\x0c\xc5' + P(tab) + b'\x89\x0a\x8b\x0c\xc5' + P(tab + 4) + b'\x89\x4a\x04'
    code += b'\xff\x05' + P(cnt) + b'\xc2\x0c\x00'
    return _code(c, code)


def _objmgr(c):
    """[0x70038c]: slot 0x20 claims a pointer (per call), +8 a converter (ecx -> ecx ^ k) for [+0xc, +0x10), slot 0xac
    writes an id before the object."""
    r = c.rng
    k = r.getrandbits(32)
    conv = _code(c, b'\x89\xc8\x35' + P(k) + b'\xc3')
    nid = r.getrandbits(32) | 1
    idw = _code(c, b'\x8b\x44\x24\x04\xc7\x40\xfc' + P(nid) + b'\xc2\x04\x00')
    m = _obj(c, 0x20, {0x20: _seq(c, 1, [r.choice((0, 0, 0, 1)) for _ in range(8)]), 0xac: idw})
    blk = c.emu.alloc(0x100, 4)
    c.emu.w32(m + 8, r.choice((0, conv, conv)))
    lo = blk + r.choice((0, 0x40, 0x80))
    c.emu.w32(m + 0xc, lo)
    c.emu.w32(m + 0x10, lo + r.choice((0x40, 0x80)))
    c.emu.w32(0x70038c, m)
    return blk


def _cptr(c, blk):
    """A pointer for ConvPtr: null, inside the manager's block, or elsewhere; the id before it is 0 or random."""
    r = c.rng
    k = r.random()
    if k < 0.15:
        return 0
    if k < 0.55:
        p = blk + 4 * r.randint(1, 0x3e)
    else:
        p = _rnd(c, 0x20) + 8
    c.emu.w32(p - 4, r.choice((0, 0, r.getrandbits(32))))
    return p


def _osd(c, k=0.85):
    r = c.rng
    o = _rnd(c, 0x2300)
    c.emu.w32(o + 0x1d0f, _rnd(c, 0x40) if r.random() < k else 0)
    return o


def _base(c):
    """Render manager, system object, database, level, OSD patches. Returns (rm, pairs, L, blk)."""
    r = c.rng
    pairs = []
    lc = r.getrandbits(32) | 1
    db = _obj(c, 0x10, {0x88: k70._dbstub(c, [lc]), 0x4c: _stub(c, 2)})
    tt = _obj(c, 0x10, {0: _stub(c, 2, ret=r.getrandbits(32))})
    rm = _obj(c, 0xb00, {0x58: k60._map(c, pairs, 0), 0x114: _seq(c, 4, [r.getrandbits(32) for _ in range(4)]),
                         0x4c: _seq(c, 1, [r.getrandbits(32) for _ in range(4)]), 0x138: _stub(c, 0, ret=db)})
    c.emu.w32(rm + 0xae4, tt)
    k70._sys(c, rm)
    L = _rnd(c, 0x2c40)
    for i in range(-1, 4):
        c.emu.w32(L + 0x2c2d + 4 * i, _osd(c))
    c.emu.w32(0x7003b8, L)
    blk = _objmgr(c)
    _patch(c, 0x59a5e0, _ecx(c, 1))
    _patch(c, 0x5aaa30, _ecx(c, 2))
    return rm, pairs, L, blk


def _finish(c, rm, pairs):
    """The render manager's handle map (slot 0x58) is built once every handle is known."""
    c.emu.w32(c.emu.r32(rm) + 0x58, k60._map(c, pairs, 0))


def _chain(c, depth):
    """A geometry for GetOwner: flags +0x3c, parent +0x50, own link +0x54; links have a type (+0xc -> +0x23), flags
    +0x30 and an owner (+8) whose parent (+0x50) holds the next link (+0x54)."""
    r = c.rng

    def link():
        e = _rnd(c, 0x40)
        t = _rnd(c, 0x30)
        c.emu.w32(t + 0x23, r.choice((0x100021, 0x100000, 0x100021, r.getrandbits(32), r.getrandbits(32) & 0xffefffff)))
        c.emu.w32(e + 0xc, t)
        c.emu.w32(e + 0x30, r.getrandbits(32) & r.choice((0, 0x4000000, 0xfbffffff, 0xffffffff)))
        return e

    g = _rnd(c, 0x60)
    c.emu.w32(g + 0x3c, r.getrandbits(32) & r.choice((0xfffbffff, 0xfffbffff, 0xfffbffff, 0xffffffff)))
    c.emu.w32(g + 0x54, link() if r.random() < 0.8 else 0)
    if r.random() < 0.3:
        c.emu.w32(g + 0x50, 0)
        return g
    p = _rnd(c, 0x60)
    c.emu.w32(g + 0x50, p)
    prev = p
    for i in range(depth):
        e = link()
        c.emu.w32(prev + 0x54, e)
        o = _rnd(c, 0x60)
        c.emu.w32(e + 8, o)
        pp = _rnd(c, 0x60) if i + 1 < depth or r.random() < 0.3 else 0
        c.emu.w32(o + 0x50, pp)
        if not pp:
            return g
        prev = pp
    c.emu.w32(prev + 0x54, 0)
    return g


def _inventory(c, h, pairs, has_c4):
    """Inventory info for C4 (14) and item 1 (and a random type); items with the slots the movement uses. Returns
    (inventory object, {type: item})."""
    r = c.rng
    vals = [0x1000, 0x2000, 0x3000]
    types = [14 if has_c4 else r.choice((2, 3, 5)), 1, r.choice((0, 2, 3, 5))]
    r.shuffle(types)
    for i in range(3):
        e = _rnd(c, 0x20)
        c.emu.w32(e, vals[i])
        c.emu.w32(e + 0x10, types[i])
        c.emu.w32(h + 0x95f + 4 * i, e)
    c.emu.w32(h + 0x95b, 3)
    hs, items = [], {}
    for i, v in enumerate(vals):
        it = _obj(c, 0x40, {0x2e8: _code(c, b'\x8b\x41\x08\xc3'), 0x2d0: _seq(c, 2, [0]), 0x7c: _copy2(c, 2),
                            0x2f0: _seq(c, 3, [0])})
        c.emu.w32(it + 8, v)
        hh = r.getrandbits(32) | 1
        pairs.append((hh, it))
        hs.append(hh)
        items[types[i]] = it
    r.shuffle(hs)
    tab = c.emu.alloc(4 * (len(hs) + 2), 4)
    for i, hh in enumerate(hs):
        c.emu.w32(tab + 4 * (i + 1), hh)
    lst = _obj(c, 0x10, {0x48: _code(c, b'\x8b\x44\x24\x04\xc7\x00' + P(len(hs) + 1) + b'\xc2\x04\x00'),
                         0x58: _code(c, b'\x8b\x4c\x24\x04\x8b\x01\x85\xc0\x74\x0a\x48\x89\x01\x8b\x04\x85' + P(tab)
                                     + b'\xc2\x04\x00')})
    return _obj(c, 0x10, {0xa0: _stub(c, 0, ret=lst)}), items


def _hero(c, hp, pairs, has_c4):
    r = c.rng
    h = k71._hero(c, hp, None)
    inv, items = _inventory(c, h, pairs, has_c4)
    vt = c.emu.r32(h)
    nv = c.emu.alloc(0x600, 4)
    c.emu.wbytes(nv, c.emu.rbytes(vt, 0x5a0))
    hand = r.choice([0, r.getrandbits(32)] + list(items.values()) + ([items[14]] * 3 if 14 in items else []))
    for off, code in ((0x464, _stub(c, 0, ret=inv)), (0x504, _stub(c, 0, ret=hand)),
                      (0x438, _stub(c, 0, ret=r.choice((0, 0, 0, 0, 0, 1, 0x100)))), (0x12c, _seq(c, 3, [0])),
                      (0x80, k71._getter(c, hp, 0))):
        c.emu.w32(nv + off, code)
    c.emu.w32(h, nv)
    c.emu.w32(h + 8, _chain(c, r.randint(0, 4)))
    c.emu.wbytes(h + 0x684, bytes([r.choice((1, 1, 2, 3, 4, 0))]))
    c.emu.wf32(c.emu.r32(h + 0x852) + 0x1d13, r.choice((0.0, 0.0, 0.0, 2 ** -13, 2 ** -12, -1.0, NAN)))
    c.emu.w32(h + 0x9d3, r.choice((13, 13, 13, 12, 0, r.getrandbits(32))))
    c.emu.wbytes(h + 0x66c, bytes([r.choice((0, 1, 1, 1))]))
    return h, items


def _follower(c, base, pairs):
    r = c.rng
    p = [base[0] + r.uniform(-500, 500), base[1] + r.uniform(-200, 200), base[2] + r.uniform(-500, 500)]
    if r.random() < 0.03:
        p[r.randint(0, 2)] = NAN
    return _obj(c, 0x100, {0x84: _stub(c, 1, skip=(0,), fills=((0, _fv(c, p), 3),)), 0x128: _resp(c)})


def _points(c, base, pairs):
    """A safe-point list: +0x18 a handle iterator; each handle maps to an object with a position (slot 0x84)."""
    r = c.rng
    hs = []
    for _ in range(r.choice((0, 1, 2, 3, 5, r.randint(0, 17)))):
        hh = r.getrandbits(32) | 1
        p = [base[0] + r.uniform(-800, 800), base[1] + r.uniform(-100, 100), base[2] + r.uniform(-800, 800)]
        pairs.append((hh, _obj(c, 0x100, {0x84: _stub(c, 1, skip=(0,), fills=((0, _fv(c, p), 3),))})))
        hs.append(hh)
    lst = _rnd(c, 0x40)
    c.emu.w32(lst + 0x18, _iter(c, hs, r.choice((0, r.getrandbits(32)))) if r.random() < 0.95 else 0)
    return lst


def _followers(c, h, hp, pairs):
    r = c.rng
    n = r.choice((0, 1, 2, 3, 4))
    c.emu.w32(h + 0xa16, n)
    for i in range(n):
        c.emu.w32(h + 0xa1a + 0x30 * i, _follower(c, hp, pairs))


def _bombgeom(c, hp):
    r = c.rng
    bp = [hp[0] + r.uniform(-60, 60), hp[1] + r.uniform(-60, 60), hp[2] + r.uniform(-60, 60)]
    return _obj(c, 0x80, {0x84: _stub(c, 1, skip=(0,), fills=((0, _fv(c, bp), 3),))})


def _spots(c, L, hp, pairs):
    """Bomb spots: [L+0xb61] count, pointers from +0xb65; +0x64 a weight, +0x44 the geometry."""
    r = c.rng
    n = r.choice((0, 1, 1, 2, 3, 5))
    c.emu.w32(L + 0xb61, n)
    gs = []
    for i in range(n):
        e = _rnd(c, 0x80)
        c.emu.wf32(e + 0x64, r.choice((1.0, 1.0, 5.0, 0.0, -1.0, NAN)))
        safe = _points(c, hp, pairs) if r.random() < 0.8 else 0
        rad = r.choice((300.0, 500.0, r.uniform(0, 1000)))
        g = _obj(c, 0x200, {0x80: k71._getter(c, hp, 50), 0x8c: _stub(c, 1, skip=(0,), copy=(0, Q3)),
                            0x180: _stub(c, 2, skip=(0,), copy=(0, Q3), ret=r.choice((0, 0, 1, 1, 0x100))),
                            0x130: _msg2(c, [[r.getrandbits(32), r.getrandbits(32)],
                                             [safe, struct.unpack('<I', struct.pack('<f', rad))[0]]]),
                            0x84: _stub(c, 1, skip=(0,), fills=((0, _vec(c, hp, 60), 3),))})
        c.emu.w32(e + 0x44, g)
        c.emu.w32(L + 0xb65 + 4 * i, e)
        gs.append(g)
    return gs


def _anim(c):
    r = c.rng
    a = _rnd(c, 0x80)
    c.emu.w32(a + 0x60, r.choice((0, 0, 1)))
    c.emu.w32(a + 0x64, r.choice((140, 160, 200, r.randint(20, 260))))
    c.emu.w32(a + 0x6c, r.choice((25, 30, r.randint(1, 60))))
    return a


def _setup(c, has_c4=None):
    """Returns (self, hero, hero pos, items, spot geometries, L)."""
    r = c.rng
    hp = [r.uniform(-2000, 2000) for _ in range(3)]
    if r.random() < 0.03:
        hp[r.randint(0, 2)] = NAN
    rm, pairs, L, blk = _base(c)
    if has_c4 is None:
        has_c4 = r.random() < 0.7
    h, items = _hero(c, hp, pairs, has_c4)
    _followers(c, h, hp, pairs)
    gs = _spots(c, L, hp, pairs)
    pts = _points(c, hp, pairs) if r.random() < 0.8 else 0
    _finish(c, rm, pairs)
    s = _obj(c, 0x600, {0x48: _stub(c, 5, ret=r.choice((0, 1, 0x100)))})
    c.emu.w32(s + 0x36d, h)
    c.emu.wbytes(s + 0x54c, bytes([r.choice((0, 1, 1)), r.choice((0, 1)), r.choice((0, 0, 1)), r.choice((0, 0, 1))]))
    now = c.emu.r32(c.emu.r32(0x70039c) + 0x40)
    nows = (now if now < 1 << 31 else now - (1 << 32)) / 1024.0
    c.emu.wf32(s + 0x550, r.choice((nows, nows - r.uniform(0, 1), nows - r.uniform(0, 10), nows - r.uniform(3, 9))))
    a = _anim(c) if r.random() < 0.95 else 0
    c.emu.w32(s + 0x554, a)
    c.emu.w32(s + 0x558, r.choice(gs) if gs and r.random() < 0.7 else _bombgeom(c, hp))
    c.emu.w32(s + 0x55c, _cptr(c, blk))
    c.emu.w32(s + 0x560, pts)
    c.emu.wf32(s + 0x564, r.choice((300.0, 500.0, r.uniform(0, 1500), NAN)))
    if a and r.random() < 0.35:
        _exact_at(c, s, 0x550, a, (0, 32, 128, c.emu.r32(a + 0x64) - c.emu.r32(a + 0x60) + 1))
    return s, h, hp, items, gs, L, blk


def _conv(c):
    rm, pairs, L, blk = _base(c)
    c.emu.mu.ctl_flush_tb()
    return [_cptr(c, blk)]


def _owner(c):
    r = c.rng
    _base(c)
    g = _chain(c, r.randint(0, 5))
    c.emu.mu.ctl_flush_tb()
    return [g, r.choice((0, 1, 0x100, 0xff))]


def _madd(c):
    r = c.rng
    _base(c)
    c.emu.mu.ctl_flush_tb()
    return [_osd(c, 0.7), r.getrandbits(32), r.choice((0xffffffff, 0, r.getrandbits(32))), r.choice((0, 1, 2, 7))]


def _send(c):
    r = c.rng
    hp = [r.uniform(-2000, 2000) for _ in range(3)]
    rm, pairs, L, blk = _base(c)
    h = _rnd(c, 0xc00)
    _followers(c, h, hp, pairs)
    g = _bombgeom(c, hp)
    pts = _points(c, hp, pairs)
    _finish(c, rm, pairs)
    c.emu.mu.ctl_flush_tb()
    return [h, g, F(r.choice((300.0, 500.0, r.uniform(0, 1500), NAN))), pts]


def _want(c):
    s, h, hp, items, gs, L, blk = _setup(c)
    c.emu.mu.ctl_flush_tb()
    return [s, _vec(c, hp, 1), _vec(c, hp, 30), _vec(c, hp, 1)]


def _got(c):
    s, h, hp, items, gs, L, blk = _setup(c, has_c4=c.rng.random() < 0.9)
    c.emu.mu.ctl_flush_tb()
    return [s]


def _gaa(c):
    s, h, hp, items, gs, L, blk = _setup(c, has_c4=True)
    out = _rnd(c, 4)
    c.emu.mu.ctl_flush_tb()
    return [s, out, 0, 0, 0, 0]


S(0x41e680, 'ConvPtr', 'fastcall', None, ret='eax', gen=_conv, note='batch74')
S(0x4db2f0, 'ZBaseGeom::GetOwner', 'thiscall', None, ret='eax', gen=_owner, note='batch74')
S(0x59a580, 'ZGameOSD::MessageAdd', 'thiscall', None, ret=None, gen=_madd, note='batch74; PlaySound, OSD patched')
S(0x594c30, 'ZFFHERO::SendFollowersToSafepoints', 'thiscall', None, ret=None, gen=_send, note='batch74')
S(0x5e8ae0, 'ZFFHeroMovementPlaceC4::WantControl', 'thiscall', None, ret='al', gen=_want, note='batch74')
S(0x5e5890, 'ZFFHeroMovementPlaceC4::GotControl', 'thiscall', None, ret=None, gen=_got, note='batch74')
S(0x5e34c0, 'ZFFHeroMovementPlaceC4::GetActiveAnim', 'thiscall', None, ret='st0', gen=_gaa, note='batch74')
