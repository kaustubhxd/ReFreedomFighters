"""specs_s8819.py - hitreact batch 8819: vmin 0x4e0900, vmax 0x4e08d0, ZBaseGeom::GetSize 0x4db7c0 and ConstrainedParticleSystem::FindFaces
0x545950. In FindFaces, PSVECSubtract / d = a + b / vscalar / mreset / GetCen / GetRootPoint (with vmmul / PSVECAdd) / vmin / vmax /
GetSize run as exe code. Patched to recording stubs: __builtin_new 0x41e290 (records n, returns a fresh 0x93-byte block; never 0, since
the original then writes through null), ZFastBoxColi1::ZFastBoxColi1 0x6353d0 (records its four arguments, returns this) and
ZFastBoxColi1::SetBox 0x635eb0 (records this, the centre, the 3x3 orientation, the half size and the flag). The geom list is an object
(slot 0x4c start, slot 0x5c next id with the cookie set while more); the render manager's slot 0x54 maps id -> geom (id + 0x100)."""
import struct
from pilot import S
from wkit import rnd, obj, fedge, sysobj
from dkit import patch_jmp, iter_stub


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _vec(c, edge=0.15):
    a = c.emu.alloc(16, 4)
    for k in range(3):
        c.emu.wf32(a + 4 * k, fedge(c) if c.rng.random() < edge else c.rng.uniform(-100, 100))
    return a


def _gen_v2(c):
    return [_vec(c, 0.3), _vec(c, 0.3)]


def _gen_size(c):
    return [rnd(c, 0x60), c.emu.alloc(16, 4)]


def _rec_stub(c, words, pops, ret_this, this=True):
    """thiscall/cdecl recorder: copies `words` = list of (kind, stack offset, count) into a log (ring of 4 calls); returns ecx or BLOCK."""
    log = c.emu.alloc(4 * 32 * 4, 4)
    cnt = c.emu.alloc(4, 4)
    body = b'\x56\x57\x8b\x3d' + struct.pack('<I', cnt) + b'\x83\xe7\x03\x6b\xf7\x7f\x81\xc6' + struct.pack('<I', log)   # esi = log + (cnt&3)*127
    if this:
        body += b'\x89\x0e'                                                                     # [esi] = ecx (thiscall only)
    o = 4
    for kind, so, n in words:
        if kind == 'v':        # stack value
            body += b'\x8b\x44\x24' + bytes([so + 8]) + b'\x89\x46' + bytes([o]); o += 4
        else:                  # pointer contents
            body += b'\x8b\x54\x24' + bytes([so + 8])
            for j in range(n):
                body += b'\x8b\x42' + bytes([4 * j]) + b'\x89\x46' + bytes([o]); o += 4
    assert o < 0x7f
    body += b'\xff\x05' + struct.pack('<I', cnt) + b'\x5f\x5e'
    if ret_this is True:
        body += b'\x8b\xc1'
    elif ret_this:
        body += b'\xb8' + struct.pack('<I', ret_this)
    body += (b'\xc2' + struct.pack('<H', pops)) if pops else b'\xc3'
    return _code(c, body)


def _gen_ff(c):
    r = c.rng
    emu = c.emu
    n = r.choice((0, 1, 3, 16, 16))
    base = emu.alloc(0x34 * 16 + 0x40, 4)
    emu.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x34 * 16 + 0x40)))
    cx, cy, cz = (r.uniform(-500, 500) for _ in range(3))
    for i in range(16):
        for o in (0, 0xc):
            for k, cc in enumerate((cx, cy, cz)):
                v = cc + r.uniform(-60, 60)
                if r.random() < 0.01:
                    v = fedge(c)
                emu.wf32(base + i * 0x34 + o + 4 * k, v)
    block = emu.alloc(0x100, 4)
    patch_jmp(c, 0x41e290, _rec_stub(c, [('v', 4, 1)], 0, block, this=False))
    patch_jmp(c, 0x6353d0, _rec_stub(c, [('v', 4, 1), ('v', 8, 1), ('v', 12, 1), ('v', 16, 1)], 0x10, True))
    patch_jmp(c, 0x635eb0, _rec_stub(c, [('p', 4, 3), ('p', 8, 9), ('p', 12, 3), ('v', 16, 1)], 0x10, False))
    rm = sysobj(c, {0x54: _code(c, b'\x8b\x44\x24\x04\x05\x00\x01\x00\x00\xc2\x04\x00')})
    ng = r.choice((0, 1, 2, 4))
    ids = []
    for i in range(ng):
        g = rnd(c, 0x60)
        for k in range(9):
            emu.wf32(g + 4 * k, r.uniform(-1, 1))
        for k in range(3):
            emu.wf32(g + 0x24 + 4 * k, r.uniform(-50, 50))
            emu.wf32(g + 0x30 + 4 * k, (cx, cy, cz)[k] + r.uniform(-150, 150))
            emu.wf32(g + 0x40 + 4 * k, r.uniform(0, 80) if r.random() < 0.95 else fedge(c))
        if r.random() < 0.2:
            pg = rnd(c, 0x60)
            for k in range(9):
                emu.wf32(pg + 4 * k, 1.0 if k in (0, 4, 8) else 0.0)
            for k in range(3):
                emu.wf32(pg + 0x24 + 4 * k, r.uniform(-20, 20))
            emu.w32(pg + 0x50, 0)
            emu.w32(g + 0x50, pg)
        else:
            emu.w32(g + 0x50, 0)
        ids.append(g - 0x100)
    gl = obj(c, 0x40, {0x4c: _code(c, b'\xc2\x04\x00'), 0x5c: iter_stub(c, ids)})
    self = rnd(c, 0x80)
    emu.w32(self + 0xf, base)
    emu.w32(self + 0x28, n)
    emu.w32(self + 0x5d, 0 if r.random() < 0.4 else rnd(c, 0x80))
    emu.w32(self + 0xa, gl if r.random() < 0.9 else 0)
    emu.mu.ctl_flush_tb()
    return [self]


S(0x4e0900, 'vmin', 'fastcall', ret=None, gen=_gen_v2)
S(0x4e08d0, 'vmax', 'fastcall', ret=None, gen=_gen_v2)
S(0x4db7c0, 'ZBaseGeom::GetSize', 'thiscall', ret=None, gen=_gen_size)
S(0x545950, 'FindFaces', 'thiscall', ret=None, gen=_gen_ff)
