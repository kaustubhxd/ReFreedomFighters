"""specs_s73.py - inline session batch 73: raising an enemy flag. CEnemyFlag::FlagPole and the flag's Activate,
stop and raised-by helpers, CSaveMissions GetNumPrimaryObjectives and GetNumPrimaryObjectivesCompleted,
ZFFHERO::SetRaisingFlag and ZFFHeroMovementRaiseFlag WantControl, GotControl, TerminateControl, Move and
GetActiveAnim. StashItem, SetUseAction, ProgressValue, the meter switch, createmat, vneg, vaddscalar, mpul and the
batch's own helpers run as exe code. Three callees owned by other threads are patched per run with a jump to a
recorder (the image is marked dirty so the next run restores it): CEnemyFlag::SwitchFlags (0x5c21e0, team colours and
radar), ZCamHelper::StartRaisingFlag (0x5d26c0, its recorder also logs the camera helper) and ZCamHelper::AbortRaisingFlag (0x5cd580). The flag manager at
[0x70038c] maps handles to flags (slot 0xcc); the database's "FlagList" is a list object whose +0x18 holds a handle
iterator with a random end value."""
import struct
from pilot import S
import specs_s53 as k53
import specs_s60 as k60
import specs_s70 as k70
import specs_s71 as k71
import specs_s72 as k72

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_seq, _fv = k60._seq, k60._fv
_mat, _vec, _code = k71._mat, k71._vec, k72._code
P = lambda v: struct.pack('<I', v & 0xffffffff)


def _patch(c, addr, stub):
    c.emu.wbytes(addr, b'\xb8' + P(stub) + b'\xff\xe0')
    c.emu._image_dirty = True


def _ecx(c, nargs, ret=0):
    """thiscall recorder: logs ecx and up to three args per call (four calls), returns ret."""
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(16 * 4, 4)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x03\xc1\xe0\x04\x05' + P(log) + b'\x89\x08'
    for i in range(min(nargs, 3)):
        code += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x50' + bytes([4 + 4 * i])
    code += b'\xff\x05' + P(cnt) + b'\xb8' + P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return _code(c, code)


def _iter(c, handles, end):
    """Handle iterator object: slot 0x4c(&it) starts, slot 0x5c(&it) returns the next handle; at the end it is 0 and
    the call returns end."""
    k = len(handles)
    tab = c.emu.alloc(4 * (k + 2), 4)
    c.emu.w32(tab, end)
    for i, h in enumerate(handles):
        c.emu.w32(tab + 4 * (i + 1), h)
    start = _code(c, b'\x8b\x4c\x24\x04\xc7\x01' + P(k + 1) + b'\xc2\x04\x00')
    nxt = _code(c, b'\x8b\x4c\x24\x04\x8b\x01\x85\xc0\x74\x03\x48\x89\x01\x8b\x04\x85' + P(tab) + b'\xc2\x04\x00')
    return _obj(c, 0x20, {0x4c: start, 0x5c: nxt})


def _resp(c):
    """slot 0x128 (cmd, data*, sender), ret 0xc: logs cmd and sender per call (eight calls) and, when data is not
    null, writes a random answer through it."""
    r = c.rng
    src = c.emu.alloc(4, 4)
    c.emu.w32(src, r.choice((0, 0, 0, 1, r.getrandbits(32))))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(64, 4)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x07\x8b\x54\x24\x04\x89\x14\xc5' + P(log)
    code += b'\x8b\x54\x24\x0c\x89\x14\xc5' + P(log + 4) + b'\xff\x05' + P(cnt)
    code += b'\x8b\x44\x24\x08\x85\xc0\x74\x08\x8b\x15' + P(src) + b'\x89\x10\xc2\x0c\x00'
    return _code(c, code)


def _flag(c, pairs, hero_pos, team_of_hero):
    r = c.rng
    f = _rnd(c, 0x200)
    geo = _obj(c, 0x140, {0x128: _resp(c), 0x12c: _seq(c, 3, [0]), 0x80: k71._getter(c, hero_pos, 120)})
    c.emu.w32(f + 0x44, geo)
    team = r.choice((team_of_hero, r.randint(0, 3), r.randint(0, 3)))
    base = r.choice((0, 0, 1))
    c.emu.w32(f + 0x48, team)
    c.emu.w32(f + 0xe8, base)
    names = c.emu.alloc(4 * 8, 4)
    for i in range(8):
        c.emu.w32(names + 4 * i, r.getrandbits(32))
    c.emu.w32(f + 0xe4, names - 4 * base)
    tf = [r.choice((0, _obj(c, 0x140, {0x128: _seq(c, 3, [0])}))) for _ in range(2)]
    c.emu.w32(f + 0x10d, _obj(c, 0x300, {0x25c: _seq(c, 2, tf)}))
    h = 0
    if r.random() < 0.5:
        h = r.getrandbits(32) | 1
        if r.random() < 0.85:
            pairs.append((h, _obj(c, 0x140, {0x128: _seq(c, 3, [0])})))
    c.emu.w32(f + 0x111, h)
    ph = 0
    if r.random() < 0.6:
        ph = r.getrandbits(32) | 1
        if r.random() < 0.9:
            pairs.append((ph, _obj(c, 0x140, {0x80: k71._getter(c, [hero_pos[0], hero_pos[1] + r.uniform(-150, 150),
                                                                    hero_pos[2]], 120)})))
    c.emu.w32(f + 0x115, ph)
    c.emu.wbytes(f + 0x106, bytes([r.choice((0, 0, 1))]))
    return f


def _level(c):
    r = c.rng
    L = _rnd(c, 0x2c20)
    lc = _rnd(c, 0xc00)
    names = [b'C01A', b'C01B', b'C02A', b'C01A_x', b'C0']
    c.emu.wbytes(lc + 0x48, r.choice(names[:4]) + b'\0')
    sm = lc + 0x50f
    n = r.choice((0, 1, 2, 3, 5, r.randint(0, 8)))
    c.emu.w32(sm + 0x5b8, n if r.random() < 0.95 else 0xffffffff)
    for i in range(min(n, 8)):
        s = c.emu.alloc(16, 4)
        c.emu.wbytes(s, r.choice(names) + b'\0')
        c.emu.w32(sm + 8 + 4 * i, s)
        c.emu.w32(sm + 0x5c0 + 4 * i, r.choice((0, 0, 0, 1)))
        c.emu.w32(sm + 0x3c8 + 4 * i, r.choice((0, 1, 1)))
    c.emu.w32(L + 0x2c15, lc)
    c.emu.w32(0x7003b8, L)
    return lc


def _hero(c, hp, team):
    r = c.rng
    cam = _rnd(c, 0x40)
    h = _obj(c, 0xa00, {0x59c: _stub(c, 2, skip=(0, 1), fills=((0, _mat(c), 9), (1, _fv(c, hp), 3))),
                        0x5a4: _stub(c, 0, ret=r.choice((0, 1, 1, 1, 0x100))),
                        0x5b4: _stub(c, 0, fld=_fv(c, [r.choice((0.0, 50.0, r.uniform(-80, 80)))])),
                        0x5c8: _stub(c, 0, ret=r.getrandbits(32) & r.choice((0xfffbffff, 0xffffffff, 0x40000))),
                        0x100: _stub(c, 1, ret=cam), 0x3dc: _stub(c, 0), 0x480: _stub(c, 1),
                        0x504: _stub(c, 0, ret=r.choice((0, r.getrandbits(32))))})
    tobj = _rnd(c, 0x10)
    c.emu.w32(tobj + 4, team)
    c.emu.w32(h + 0x54, tobj)
    c.emu.w32(h + 0x852, _rnd(c, 0x2300))
    c.emu.w32(h + 0x85a, r.choice((0, cam, cam)))
    c.emu.w32(h + 0x832, r.choice((0, 0, r.getrandbits(32))))
    c.emu.w32(h + 0x836, r.getrandbits(32) & r.choice((0, 4, 0xffffffff)))
    c.emu.wbytes(h + 0x9e7, bytes([r.choice((0, 1, 1))]))
    c.emu.w32(h + 0x9d3, r.choice((2, 2, 2, 8, 0, r.getrandbits(32))))
    c.emu.wbytes(h + 0x66c, bytes([r.choice((0, 1, 1))]))
    c.emu.wf32(h + 0x9e3, r.choice((0.0, 0.0, r.uniform(1, 100))))
    return h


def _anim(c):
    r = c.rng
    a = _rnd(c, 0x80)
    c.emu.w32(a + 0x60, r.choice((0, 0, 1)))
    c.emu.w32(a + 0x64, r.choice((70, 90, 150, r.randint(30, 260))))
    c.emu.w32(a + 0x6c, r.choice((25, 30, r.randint(1, 60))))
    return a


def _exact_at(c, s, off, anim, thrs):
    r = c.rng
    rate = r.choice((16, 32, 64))
    c.emu.w32(anim + 0x6c, rate)
    now = c.emu.r32(c.emu.r32(0x70039c) + 0x40)
    now = now if now < 1 << 31 else now - (1 << 32)
    c.emu.wf32(s + off, (now - r.choice(thrs) * 1024 // rate) / 1024.0)


def _setup(c, need_flag=False):
    """Returns (self, hero pos)."""
    r = c.rng
    hp = [r.uniform(-2000, 2000) for _ in range(3)]
    if r.random() < 0.03:
        hp[r.randint(0, 2)] = float('nan')
    team = r.randint(0, 3)
    _level(c)
    pairs = []
    while True:
        flags = [_flag(c, pairs, hp, team) for _ in range(r.choice((0, 1, 1, 2, 3)))]
        if flags or not need_flag:
            break
    fpairs = [(r.getrandbits(32) | 1, f) for f in flags]
    hs = [h for h, _ in fpairs] + [r.getrandbits(32) | 1 for _ in range(r.choice((0, 0, 1)))]
    r.shuffle(hs)
    lst = _rnd(c, 0x40)
    end = r.choice((0, 0, r.getrandbits(32), hs[0] if hs else 0))
    c.emu.w32(lst + 0x18, _iter(c, hs, end) if r.random() < 0.9 else 0)
    lh = r.getrandbits(32) | 1
    if r.random() < 0.9:
        pairs.append((lh, lst))
    db = _obj(c, 0x10, {0x88: k70._dbstub(c, [lh])})
    rm = _obj(c, 0x140, {0x58: k60._map(c, pairs, 0), 0x114: _seq(c, 4, [r.getrandbits(32) for _ in range(4)]),
                         0x4c: _seq(c, 1, [r.getrandbits(32) for _ in range(3)]), 0x138: _stub(c, 0, ret=db)})
    k70._sys(c, rm)
    c.emu.w32(0x70038c, _obj(c, 0x100, {0xcc: k60._map(c, fpairs, 0)}))
    _patch(c, 0x5c21e0, _stub(c, 1))
    _patch(c, 0x5d26c0, _ecx(c, 1))
    _patch(c, 0x5cd580, _stub(c, 0))
    h = _hero(c, hp, team)
    owner = h if r.random() < 0.7 else _hero(c, hp, team)
    s = _obj(c, 0x600, {0x48: _stub(c, 5, ret=r.choice((0, 1, 0x100)))})
    c.emu.w32(s + 4, owner)
    c.emu.w32(s + 0x36d, h)
    c.emu.wbytes(s + 0x550, bytes([r.choice((0, 1, 1))] + [r.choice((0, 0, 1)) for _ in range(4)]))
    now = c.emu.r32(c.emu.r32(0x70039c) + 0x40)
    nows = (now if now < 1 << 31 else now - (1 << 32)) / 1024.0
    c.emu.wf32(s + 0x555, r.choice((nows, nows - r.uniform(0, 0.4), nows - r.uniform(0, 10), nows - r.uniform(1, 5))))
    for off in (0x559, 0x55d, 0x561):
        c.emu.w32(s + off, _anim(c) if r.random() < 0.93 else 0)
    c.emu.w32(s + 0x565, r.choice((0, 0, lh, r.getrandbits(32))))
    c.emu.w32(s + 0x569, r.choice([h for h, _ in fpairs] * 3 + [0, r.getrandbits(32)]) if fpairs else 0)
    c.emu.wbytes(s + 0x56d, b''.join(struct.pack('<f', r.uniform(-500, 500)) for _ in range(6)))
    c.emu.wbytes(s + 0x585, b''.join(struct.pack('<f', r.uniform(-1, 1)) for _ in range(18)))
    a = c.emu.r32(s + 0x559)
    if a and r.random() < 0.3:
        _exact_at(c, s, 0x555, a, (0, 45, 60, c.emu.r32(a + 0x64) - c.emu.r32(a + 0x60) + 1))
    return s, hp, flags


def _flagonly(c):
    s, hp, flags = _setup(c, need_flag=True)
    c.emu.mu.ctl_flush_tb()
    return [c.rng.choice(flags)]


def _raisedby(c):
    r = c.rng
    s, hp, flags = _setup(c, need_flag=True)
    c.emu.mu.ctl_flush_tb()
    return [r.choice(flags), c.emu.r32(s + 0x36d)]


def _sm(c):
    r = c.rng
    lc = _level(c)
    nm = c.emu.alloc(16, 4)
    c.emu.wbytes(nm, r.choice((b'C01A', b'C01B', b'C02A', b'C0', b'C01A_y')) + b'\0')
    c.emu.mu.ctl_flush_tb()
    return [lc + 0x50f, r.choice((nm, lc + 0x48))]


def _srf(c):
    r = c.rng
    s, hp, flags = _setup(c)
    c.emu.mu.ctl_flush_tb()
    return [c.emu.r32(s + 0x36d), r.choice((0, 1, 0x100)), r.choice(flags + [0]) if flags else 0]


def _term(c):
    s, _, _ = _setup(c)
    c.emu.mu.ctl_flush_tb()
    return [s, c.rng.choice((0, 1, 0x100))]


def _want(c):
    s, hp, _ = _setup(c)
    c.emu.mu.ctl_flush_tb()
    return [s, _vec(c, hp, 1), _fv(c, hp), _vec(c, hp, 1)]


def _got(c):
    s, _, flags = _setup(c, need_flag=True)
    c.emu.mu.ctl_flush_tb()
    return [s]


def _move(c):
    r = c.rng
    s, hp, _ = _setup(c)
    m = _mat(c) if r.random() < 0.5 else _fv(c, [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0])
    if r.random() < 0.3:
        c.emu.wbytes(s + 0x5a9, c.emu.rbytes(s + 0x585, 36))
    outm, outp, outv = _rnd(c, 0x30), _rnd(c, 0x10), _rnd(c, 0x10)
    c.emu.mu.ctl_flush_tb()
    return [s, m, _vec(c, hp, 50), outm, outp, outv]


def _gaa(c):
    s, _, _ = _setup(c, need_flag=True)
    out = _rnd(c, 4)
    c.emu.mu.ctl_flush_tb()
    return [s, out, 0, 0, 0, 0]


S(0x5c1650, 'CEnemyFlag::FlagPole', 'thiscall', None, ret='eax', gen=_flagonly, note='batch73')
S(0x5c1d10, 'CEnemyFlag Activate', 'thiscall', None, ret=None, gen=_flagonly, note='batch73')
S(0x5c1f70, 'CEnemyFlag stop', 'thiscall', None, ret=None, gen=_flagonly, note='batch73')
S(0x5c21c0, 'CEnemyFlag raised by', 'thiscall', None, ret=None, gen=_raisedby, note='batch73; SwitchFlags patched')
S(0x5b0bf0, 'CSaveMissions::GetNumPrimaryObjectives', 'thiscall', None, ret='eax', gen=_sm, note='batch73')
S(0x5b0c50, 'CSaveMissions::GetNumPrimaryObjectivesCompleted', 'thiscall', None, ret='eax', gen=_sm, note='batch73')
S(0x594fb0, 'ZFFHERO::SetRaisingFlag', 'thiscall', None, ret=None, gen=_srf, note='batch73; camera patched')
S(0x5e8d40, 'ZFFHeroMovementRaiseFlag::WantControl', 'thiscall', None, ret='al', gen=_want, note='batch73')
S(0x5e5950, 'ZFFHeroMovementRaiseFlag::GotControl', 'thiscall', None, ret=None, gen=_got, note='batch73')
S(0x5e7480, 'ZFFHeroMovementRaiseFlag::TerminateControl', 'thiscall', None, ret='al', gen=_term, note='batch73')
S(0x5e7000, 'ZFFHeroMovementRaiseFlag::Move', 'thiscall', None, ret=None, gen=_move, note='batch73; mpul as exe code')
S(0x5e3920, 'ZFFHeroMovementRaiseFlag::GetActiveAnim', 'thiscall', None, ret='st0', gen=_gaa, note='batch73')
