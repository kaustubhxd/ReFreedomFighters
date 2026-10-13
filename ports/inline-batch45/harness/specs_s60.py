"""specs_s60.py - inline session batch 60: ZFFHeroMovementMachinegun::Move.
Move runs GetFireAimPos and its whole aim chain as exe code on the batch 53 camera-helper setup (imported from
specs_s53). The render manager's slot 0x58 is a map stub (gun, centre and weapon handles to their objects, anything
else to the aim-target actor of the batch 53 setup) that logs each handle; createmat, vneg and vaddscalar run as exe
code; hero, gun, centre and weapon calls are heap recorder stubs."""
import re
import struct
from pilot import S
import specs_s53 as k53

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
XYZ = [(0, 'd'), (4, 'd'), (8, 'd')]


def _fv(c, vals):
    a = c.emu.alloc(4 * len(vals) + 4, 4)
    c.emu.wbytes(a, b''.join(struct.pack('<f', v) for v in vals))
    return a


def _b(c, p):
    return c.rng.getrandbits(32) & (0xffffff00 if c.rng.random() < p else 0xffffffff)


def _seq(c, nargs, rets):
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


def _map(c, pairs, dflt):
    """thiscall (handle), ret 4: logs the handle per call (eight calls) and returns the object for it."""
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(32, 4)
    code = b'\xa1' + struct.pack('<I', cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x8b\x54\x24\x04\x89\x90' + struct.pack('<I', log)
    code += b'\xff\x05' + struct.pack('<I', cnt)
    for h, o in pairs:
        code += b'\x81\x7c\x24\x04' + struct.pack('<I', h) + b'\x75\x08\xb8' + struct.pack('<I', o) + b'\xc2\x04\x00'
    code += b'\xb8' + struct.pack('<I', dflt & 0xffffffff) + b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _shf(c):
    r = c.rng
    hero = _rnd(c, 0x700)
    c.emu.wbytes(hero + 0x669, bytes([r.choice((0, 1, r.randint(0, 255)))]))
    c.emu.wbytes(hero + 0x66b, bytes([r.choice((0, 1, r.randint(0, 255)))]))
    return [hero, r.choice((0, 1, 0x100, 0x101, r.getrandbits(32)))]


def _mgm(c):
    r = c.rng
    cam = k53._fireaim_cam(c)
    rm = c.emu.r32(c.emu.r32(0x70039c) + 0x9b)
    oldvt = c.emu.r32(rm)
    old58 = c.emu.r32(oldvt + 0x58)
    m = re.search(b'\xb8(....)\xc2\x04\x00', bytes(c.emu.mu.mem_read(old58, 256)), re.S)
    tgt = struct.unpack('<I', m.group(1))[0]
    gun = _obj(c, 0x20, {0x128: _seq(c, 1, [0])})
    ctr = _obj(c, 0x20, {0x80: _stub(c, 2, fills=((0, _fv(c, r.choice(([r.uniform(-2, 2) for _ in range(3)], [0.0, r.uniform(-2, 2), 0.0], [0.0, 0.0, 0.0], [0.0, r.uniform(-2, 2), r.uniform(-2, 2)]))), 3),
                                                   (1, _fv(c, [r.uniform(-3000, 3000) for _ in range(3)]), 3)))})
    wpn = _obj(c, 0x20, {0x360: _stub(c, 1), 0x358: _stub(c, 1), 0x2d0: _stub(c, 2)})
    hs = [r.getrandbits(32) | 1 for _ in range(3)]
    rvt = c.emu.alloc(0x120, 4)
    c.emu.w32(rvt + 0x4c, c.emu.r32(oldvt + 0x4c))
    c.emu.w32(rvt + 0x58, _map(c, [(hs[0], gun), (hs[1], ctr), (hs[2], wpn)], tgt))
    c.emu.w32(rvt + 0x114, _stub(c, 6, skip=(4,), copy=(4, XYZ), ret=r.getrandbits(32)))
    c.emu.w32(rm, rvt)
    hero = _obj(c, 0xa00, {0x100: _stub(c, 1, ret=cam), 0x8c: _stub(c, 1, skip=(0,), copy=(0, XYZ)),
                           0x4b0: _stub(c, 6, skip=(0,), copy=(0, XYZ)), 0x438: _stub(c, 0, ret=_b(c, 0.8))})
    c.emu.w32(hero + 0x85a, cam if r.random() < 0.8 else 0)
    c.emu.wbytes(hero + 0x9e3, struct.pack('<f', r.choice((0.0, 0.0, -0.0, r.uniform(-5, 5)))))
    c.emu.wbytes(hero + 0x669, bytes([r.choice((0, 1, r.randint(0, 255)))]))
    c.emu.wbytes(hero + 0x66b, bytes([r.choice((0, 1))]))
    now = r.choice((r.randint(0, 1 << 20), r.getrandbits(32)))
    c.emu.w32(c.emu.r32(0x70039c) + 0x40, now)
    self = _rnd(c, 0x600)
    c.emu.w32(self + 0x36d, hero)
    for off, h in zip((0x551, 0x559, 0x555), hs):
        c.emu.w32(self + off, h)
    c.emu.w32(self + 0x58d, (now - r.choice((0x99, 0x9a, 0x98, 0, 0x1000, r.getrandbits(32)))) & 0xffffffff)
    c.emu.wbytes(self + 0x54c, bytes([r.choice((0, 1, r.randint(0, 255)))]))
    c.emu.mu.ctl_flush_tb()
    return [self, _fv(c, [r.uniform(-1, 1) for _ in range(9)]), _fv(c, [r.uniform(-3000, 3000) for _ in range(3)]),
            _fv(c, [9.0] * 9), _fv(c, [9.0] * 3), _fv(c, [9.0] * 3)]


S(0x5e6ab0, 'ZFFHeroMovementMachinegun::Move', 'thiscall', None, gen=_mgm,
  note='batch60; mounted-gun tree; GetFireAimPos chain as exe code')
