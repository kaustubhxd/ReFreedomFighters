"""specs_s59.py - inline session batch 59: ZFFHeroMovementMachinegun::GotControl and TerminateControl.
Render-manager, gun, weapon and hero vtable calls are heap stubs; the render manager's slots 0x58 and 0x114 and the
gun's slot 0x128 log every call's arguments (up to eight calls) and return per-call values. StashItem runs as exe code."""
import struct
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, nargs, fills=(), ret=0, skip=(), fld=None, copy=None, adds=(), ofills=(), peeks=()):
    """copy = (argidx, [(off, 'd'|'b'), ...]) copies fields of the struct an arg points to into the record."""
    nrec = nargs + 1 + (len(copy[1]) if copy else 0) + len(peeks)
    rec = c.emu.alloc(4 * nrec, 4)
    code = b''
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    if copy:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * copy[0]])
        for k, (off, kind) in enumerate(copy[1]):
            code += (b'\x8b\x50' if kind == 'd' else b'\x0f\xb6\x50') + bytes([off])
            code += b'\x89\x15' + struct.pack('<I', rec + 4 * (nargs + 1 + k))
    for k, addr in enumerate(peeks):   # record a dword of memory at call time
        code += b'\xa1' + struct.pack('<I', addr) + b'\xa3' + struct.pack('<I', rec + 4 * (nrec - len(peeks) + k))
    for ai, off, src, nd in ofills:   # out = [arg]+off, filled from src
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([off + 4 * j])
    for ai, src, nd in adds:   # out[j] += src[j] (SSE single adds), like a local-to-world offset
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\xf3\x0f\x10\x40' + bytes([4 * j]) + b'\xf3\x0f\x58\x05' + struct.pack('<I', src + 4 * j)
            code += b'\xf3\x0f\x11\x40' + bytes([4 * j])
    for ai, src, nd in fills:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([4 * j])
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    if fld is not None:
        code += b'\xd9\x05' + struct.pack('<I', fld)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _obj(c, size, slots):
    o = _rnd(c, size)
    vt = c.emu.alloc(max(slots) + 4, 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def _fl(c, n, lo=-200.0, hi=200.0):
    a = c.emu.alloc(4 * n + 4, 4)
    c.emu.wbytes(a, b''.join(struct.pack('<f', c.rng.uniform(lo, hi)) for _ in range(n)))
    return a


def _seq(c, nargs, rets):
    """Logs all args of each call (32-byte records, eight calls) and returns rets[call] (the last one after that)."""
    rets = list(rets) + [rets[-1]] * (8 - len(rets))
    tab = c.emu.alloc(32, 4)
    c.emu.wbytes(tab, b''.join(struct.pack('<I', v & 0xffffffff) for v in rets[:8]))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(32 * 8, 4)
    code = b'\xa1' + struct.pack('<I', cnt) + b'\x83\xe0\x07\xc1\xe0\x05\x05' + struct.pack('<I', log)
    for i in range(nargs):
        code += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x50' + bytes([4 * i])
    code += b'\xa1' + struct.pack('<I', cnt) + b'\x83\xe0\x07\x8b\x04\x85' + struct.pack('<I', tab)
    code += b'\xff\x05' + struct.pack('<I', cnt) + b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _mg(c, term):
    r = c.rng
    gun = _obj(c, 0x20, {0x128: _seq(c, 1, [0])})
    wpn = _obj(c, 0x20, {0x2d0: _stub(c, 2)})
    first, second = (wpn, gun) if term else (gun, gun)
    rm = _obj(c, 0x40, {0x58: _seq(c, 1, [first, second]), 0x4c: _stub(c, 1, ret=r.getrandbits(32)),
                        0x114: _seq(c, 6, [r.getrandbits(32) for _ in range(3)])})
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(sysobj + 0x40, r.choice((r.randint(0, 64), r.randint(-50, 5000), r.getrandbits(32))) & 0xffffffff)
    c.emu.w32(0x70039c, sysobj)
    hero = _obj(c, 0xa00, {0x504: _stub(c, 0, ret=r.getrandbits(32) if r.random() < 0.6 else 0),
                           0x3dc: _stub(c, 0), 0x480: _stub(c, 1), 0x4b4: _stub(c, 5)})
    c.emu.w32(hero + 0x836, r.choice((0, 0, 8, 1, r.getrandbits(32))))
    c.emu.w32(hero + 0x832, r.choice((0, 0, r.getrandbits(32))))
    self = _rnd(c, 0x600)
    c.emu.w32(self + 0x36d, hero)
    c.emu.wbytes(self + 0x54c, bytes([r.choice((0, 0, 1, r.randint(0, 255)))]))
    c.emu.mu.ctl_flush_tb()
    if term:
        return [self, r.getrandbits(32) & (0xffffff00 if r.random() < 0.5 else 0xffffffff)]
    return [self]


S(0x5e5300, 'ZFFHeroMovementMachinegun::GotControl', 'thiscall', None, gen=lambda c: _mg(c, False),
  note='batch59; mounted-gun tree')
S(0x5e7290, 'ZFFHeroMovementMachinegun::TerminateControl', 'thiscall', None, ret='al', gen=lambda c: _mg(c, True),
  note='batch59; mounted-gun tree')


def _fv(c, vals):
    a = c.emu.alloc(4 * len(vals) + 4, 4)
    c.emu.wbytes(a, b''.join(struct.pack('<f', v) for v in vals))
    return a


def _iter(c, k):
    """Steps a k-entry list: the out value counts down to 0, and the last step returns 0 like the game's lists."""
    cnt = c.emu.alloc(8, 4)
    c.emu.w32(cnt, k + 1)
    base = c.rng.getrandbits(32) & 0x7fff0000
    code = b'\xa1' + struct.pack('<I', cnt) + b'\x48\xa3' + struct.pack('<I', cnt) + b'\x8b\x4c\x24\x04\x89\x01'
    code += b'\x85\xc0\x74\x05\x05' + struct.pack('<I', base) + b'\xff\x05' + struct.pack('<I', cnt + 4) + b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _send(c, rets, outs):
    """Render-manager slot 0x114 for WantControl: logs args 0 to 3 and 5 per call, writes outs[call] through the
    pointer in arg 4 (a frame address, so not logged) and returns rets[call]."""
    rets = list(rets) + [rets[-1]] * 8
    outs = list(outs) + [outs[-1]] * 8
    tab = c.emu.alloc(64, 4)
    c.emu.wbytes(tab, b''.join(struct.pack('<I', v & 0xffffffff) for v in rets[:8] + outs[:8]))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(32 * 8, 4)
    code = b'\xa1' + struct.pack('<I', cnt) + b'\x83\xe0\x07\xc1\xe0\x05\x05' + struct.pack('<I', log)
    for i in (0, 1, 2, 3, 5):
        code += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x50' + bytes([4 * i])
    code += b'\x8b\x4c\x24\x14\xa1' + struct.pack('<I', cnt) + b'\x83\xe0\x07'
    code += b'\x8b\x14\x85' + struct.pack('<I', tab + 32) + b'\x89\x11'
    code += b'\x8b\x04\x85' + struct.pack('<I', tab) + b'\xff\x05' + struct.pack('<I', cnt) + b'\xc2\x18\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _local(c):
    r = c.rng
    x = r.random()
    if x < 0.15:
        return r.choice(([125.0, 0.0, -75.0], [0.0, 125.0, -75.0], [0.0, 0.0, 0.0], [0.0, 0.0, 50.0], [126.0, 0.0, -75.0],
                         [100.0, 75.0, -75.0], [0.0, 0.0, 1e-3]))
    return [r.uniform(-150, 150), r.uniform(-150, 150), r.uniform(-220, 60)]


def _hero_use(c, slots):
    r = c.rng
    hero = _obj(c, 0xa00, slots)
    c.emu.wbytes(hero + 0x9db, struct.pack('<f', r.choice((1e9, r.uniform(0, 100), 30.0, 0.0))))
    c.emu.w32(hero + 0x9d3, r.choice((4, 4, 3, 0)))
    c.emu.wbytes(hero + 0x66c, bytes([r.choice((0, 1, r.randint(0, 255)))]))
    return hero


def _sua(c):
    r = c.rng
    hero = _hero_use(c, {0: 0})
    return [hero, r.choice((4, r.getrandbits(32))), F(r.choice((r.uniform(0, 100), 30.0, 0.0, 1e9))), r.getrandbits(32)]


def _mgw(c):
    r = c.rng
    k = r.choice((0, 1, 2, 3, 4))
    guns = []
    for i in range(k):
        if r.random() < 0.1:
            guns.append(0)
            continue
        guns.append(_obj(c, 0x20, {0x8c: _stub(c, 1, skip=(0,), copy=(0, [(0, 'd'), (4, 'd'), (8, 'd')]),
                                              fills=((0, _fv(c, _local(c)), 3),)), 0x128: _seq(c, 1, [0])}))
    owner = _rnd(c, 0x20)
    lst = _obj(c, 0x10, {0x4c: _stub(c, 1, skip=(0,)), 0x5c: _iter(c, k)})
    c.emu.w32(owner + 0x18, lst if r.random() < 0.92 else 0)
    tmpv = c.emu.alloc(4, 4)
    c.emu.w32(tmpv, r.choice((0, r.getrandbits(32))))
    o = _obj(c, 0x90, {0x88: _stub(c, 2, skip=(1,), ofills=((1, 0, tmpv, 1),))})
    rm = _obj(c, 0x140, {0x138: _stub(c, 0, ret=o), 0x58: _seq(c, 1, [owner if r.random() < 0.93 else 0] + guns + [0]),
                         0x114: _send(c, [r.getrandbits(32) for _ in range(4)],
                                      [r.choice((0, 0, 1, r.getrandbits(32))) for _ in range(4)])})
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    hero = _hero_use(c, {0: 0})
    c.emu.w32(hero + 0x417, (r.getrandbits(32) & ~0x2000000) if r.random() < 0.9 else (r.getrandbits(32) | 0x2000000))
    self = _rnd(c, 0x600)
    c.emu.w32(self + 0x36d, hero)
    c.emu.w32(self + 0x54d, r.choice((0, 0, r.getrandbits(32))))
    # A stale gun handle with no list would make the exe read an unset local vector; keep inputs off that path.
    c.emu.w32(self + 0x551, r.choice((0, r.getrandbits(32))) if c.emu.r32(owner + 0x18) else 0)
    c.emu.mu.ctl_flush_tb()
    return [self, _fv(c, [1, 2, 3]), _fv(c, [r.uniform(-3000, 3000) for _ in range(3)]), _fv(c, [7, 8, 9])]


S(0x5950c0, 'ZFFHERO::SetUseAction', 'thiscall', None, gen=_sua, note='batch59; mounted-gun tree')
S(0x5e8460, 'ZFFHeroMovementMachinegun::WantControl', 'thiscall', None, ret='al', gen=_mgw, note='batch59; mounted-gun tree')
