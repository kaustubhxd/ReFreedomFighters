"""specs_s69.py - inline session batch 69: hero death. ZPlayer and ZFFActor IsDead, ZPlayer DisableCollision,
DisableControls and Die, ZFFHERO::Die and PerformDie, ZGROUP::AddSound2d and ZIKLNKOBJ::PlaySound. The hero is a
recorder object; its DisableControls and DisableCollision slots are the exe's own functions in half of the inputs.
AddSound3d runs as exe code and stops at a zero id from the sound system's slot 0x11c; the database lookup (slot
0x88) writes a handle through its out pointer; the logger's cdecl slot 0x2c logs its two arguments."""
import struct
from pilot import S, F
import specs_s53 as k53
import specs_s60 as k60

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_seq, _fv = k60._seq, k60._fv
P = lambda v: struct.pack('<I', v & 0xffffffff)


def _cdecl(c, nargs):
    """cdecl recorder: logs nargs arguments and a call count, returns 0 with a plain ret."""
    rec = c.emu.alloc(4 * nargs + 4, 4)
    code = b''
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + P(rec + 4 * i)
    code += b'\xff\x05' + P(rec + 4 * nargs) + b'\x31\xc0\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _hval(c):
    r = c.rng
    return r.choice((0, r.getrandbits(32), r.getrandbits(32)))


def _world(c):
    """Game object, render manager, database, sound system, logger and the drop list."""
    r = c.rng
    hv = c.emu.alloc(4, 4)
    c.emu.w32(hv, _hval(c))
    db = _obj(c, 0x10, {0x88: _stub(c, 2, skip=(1,), ofills=((1, 0, hv, 1),))})
    snd = _rnd(c, 0x50)
    rm = _obj(c, 0x20, {0x60: _seq(c, 1, [r.choice((snd, snd, 0))]),
                        0x114: _seq(c, 4, [r.getrandbits(32), r.getrandbits(32)]),   # per-call log: PerformDie registers two messages
                        0x138: _stub(c, 0, ret=db)})
    ss = _obj(c, 0x20, {0xf0: _stub(c, 1, ret=r.choice((0, 1, 0x100, r.getrandbits(32)))),
                        0x120: _stub(c, 2, ret=r.getrandbits(32)),
                        0x11c: _stub(c, 4, ret=0)})
    gobj = _rnd(c, 0x1ab0)
    c.emu.w32(gobj + 0x40, r.choice((r.randint(0, 1 << 22), r.getrandbits(32))))
    c.emu.w32(gobj + 0x9b, rm)
    c.emu.wf32(gobj + 0x9c7, 0.0)
    c.emu.w32(gobj + 0x1a9f, ss if r.random() < 0.85 else 0)
    c.emu.w32(0x70039c, gobj)
    l = _obj(c, 0x10, {0x2c: _cdecl(c, 2)})
    c.emu.w32(0x700390, _obj(c, 0x10, {0x20: _stub(c, 2, ret=l)}))
    return rm


def _droplist(c, it):
    r = c.rng
    L = _rnd(c, 0x8b8 + 4 * 10)
    n = r.randint(0, 6)
    c.emu.w32(L + 0x8b4, n)
    for i in range(n):
        c.emu.w32(L + 0x8b8 + 4 * i, it if r.random() < 0.15 else r.getrandbits(32))
    c.emu.w32(0x7003b8, L)


def _hero(c):
    r = c.rng
    grp = _rnd(c, 0x40)
    it = r.choice((0, r.getrandbits(32), r.getrandbits(32)))
    rh = _obj(c, 0x10, {0x10: _stub(c, 0, ret=it)})
    exe = r.random() < 0.5
    h = _obj(c, 0x1000, {0x3dc: _stub(c, 0), 0x220: _stub(c, 1), 0x368: 0x483110 if exe else _stub(c, 0),
                         0x12c: _stub(c, 3), 0x130: _stub(c, 3), 0x584: 0x483100 if exe else _stub(c, 0),
                         0x4f8: _stub(c, 0, ret=rh), 0x520: _stub(c, 1), 0x4f4: _stub(c, 1),
                         0x518: _stub(c, 1), 0x51c: _stub(c, 1), 0x20: _stub(c, 0, ret=grp)})
    c.emu.w32(h + 0x455, _obj(c, 0x10, {8: _stub(c, 1)}))
    c.emu.w32(h + 8, _rnd(c, 0x40))
    c.emu.w32(h + 0x417, r.getrandbits(32) & r.choice((0xfffbffff, 0xffffffff, 0)))
    c.emu.w32(h + 0x606, r.choice((0, 0, 1, r.getrandbits(32))))
    c.emu.w32(h + 0x846, _hval(c))
    c.emu.wbytes(h + 0x9e7, bytes([r.choice((0, 1, r.randint(0, 255)))]))
    _droplist(c, it)
    return h


def _isdead(c):
    r = c.rng
    p = _rnd(c, 0x420)
    c.emu.w32(p + 8, r.choice((0, 1, 2, 3, 4, r.getrandbits(32))))
    return [p]


def _f(c):
    r = c.rng
    return r.choice((0.0, 250.0, r.uniform(0, 500), r.uniform(-100, 100), c.fv(), float('nan'), float('inf')))


def _die(c):
    r = c.rng
    _world(c)
    h = _hero(c)
    a = _fv(c, [r.uniform(-1, 1) for _ in range(3)])
    b = _fv(c, [r.uniform(-3000, 3000) for _ in range(3)])
    c.emu.mu.ctl_flush_tb()
    return [h, a, b, F(_f(c))]


def _plain(c):
    _world(c)
    h = _hero(c)
    c.emu.mu.ctl_flush_tb()
    return [h]


def _snd2(c):
    _world(c)
    c.emu.mu.ctl_flush_tb()
    return [_rnd(c, 0x40), c.rng.getrandbits(32)]


def _psnd(c):
    _world(c)
    h = _hero(c)
    c.emu.mu.ctl_flush_tb()
    return [h, c.rng.choice((0, 1, c.rng.getrandbits(32)))]


S(0x483ee0, 'ZPlayer::IsDead', 'thiscall', None, ret='al', gen=_plain, note='batch69')
S(0x5a0ad0, 'ZFFActor::IsDead', 'thiscall', None, ret='al', gen=_isdead, note='batch69')
S(0x483100, 'ZPlayer::DisableCollision', 'thiscall', None, ret=None, gen=_plain, note='batch69')
S(0x483110, 'ZPlayer::DisableControls', 'thiscall', None, ret=None, gen=_plain, note='batch69')
S(0x4830e0, 'ZPlayer::Die', 'thiscall', None, ret=None, gen=_die, note='batch69')
S(0x5910d0, 'ZFFHERO::Die', 'thiscall', None, ret=None, gen=_die, note='batch69; DisableControls as exe code in half')
S(0x43eb80, 'ZGROUP::AddSound2d', 'thiscall', None, ret='eax', gen=_snd2, note='batch69')
S(0x466f60, 'ZIKLNKOBJ::PlaySound', 'thiscall', None, ret='eax', gen=_psnd, note='batch69; AddSound3d as exe code')
S(0x593cc0, 'ZFFHERO::PerformDie', 'thiscall', None, ret=None, gen=_plain, note='batch69; PlaySound as exe code')
