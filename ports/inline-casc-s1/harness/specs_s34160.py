"""specs_s34160.py - tier H. 0x5f4e60: kind byte +4 (2 in a half), logger + assert hook. 0x4d6150: 0x41e290 hooked (returns a block), 0x4d9350 hooked (ecx and 2 args), embedded object at this+0xa with a vptr (slot 1, 1 arg), source record 0x1a bytes. 0x5272e0: floats at +4/+8/+0x10/+0x14 around the limits, engine float at [0x70039c]+0x48. 0x45aff0: hooked 0x4dd060 / 0x4dce50, child floats at +0x40.., real sqrt stub."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec
from pe_emu import DEFAULT_EXE
import pefile

_pe = pefile.PE(DEFAULT_EXE)
_img = _pe.OPTIONAL_HEADER.ImageBase


def _const(addr):
    return struct.unpack('<f', _pe.get_data(addr - _img, 4))[0]


def _fbits(r, center=None):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    elif center is not None and k < 0.5:
        v = center + r.choice([0.0, 1e-6, -1e-6, 0.01, -0.01, 1.0, -1.0, 0.5, 1.2e-4, -1.2e-4])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g5f4e60(c):
    clear_hooks(c)
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))
    pr = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)}, nslots=0x30 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=pr, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, lg)
    me = rnd(c, 0x20)
    c.emu.w32(me, _fbits(r))
    c.emu.wbytes(me + 4, bytes([r.choice([2, 2, 2, 0, 1, 3, 0x82])]))
    p = rnd(c, 0x10)
    c.emu.w32(p, _fbits(r))
    return [me, p]


def _g4d6150(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, ret=blk, pop=0)
    hook_rec(c, 0x4d9350, 2, this=True, pop=8, ret=r.getrandbits(32))
    vt = c.emu.alloc(0x20, 4)
    c.emu.w32(vt + 4, pystub(c, 1, this=True))
    me = rnd(c, 0x20)
    c.emu.wbytes(me + 0xa, vt.to_bytes(4, 'little'))
    b = rnd(c, 0x20)
    return [me, r.getrandbits(32), b, r.getrandbits(32)]


def _g5272e0(c):
    clear_hooks(c)
    r = c.rng
    k = _const(0x679540)
    so = rnd(c, 0x60)
    c.emu.w32(so + 0x48, _fbits(r))
    c.emu.w32(0x70039c, so)
    me = rnd(c, 0x40)
    f = r.choice([1.0, -1.0, 0.0, -0.0, 3.0, -3.0, 0.5])
    c.emu.w32(me + 0x14, struct.unpack('<I', struct.pack('<f', f))[0] if r.random() < 0.7 else _fbits(r))
    c.emu.w32(me + 0x10, struct.unpack('<I', struct.pack('<f', r.choice([1.0, 2.0, 0.5, -1.0]))) [0] if r.random() < 0.7 else _fbits(r))
    lim = r.choice([0.0, 10.0, -10.0, 100.0, r.uniform(-50, 50)])
    c.emu.w32(me + 8, struct.unpack('<I', struct.pack('<f', lim))[0] if r.random() < 0.85 else _fbits(r))
    x = lim + r.choice([k, -k, 2 * k, -2 * k, 0.0, 1.0, -1.0, 5.0, -5.0, k / 2])
    c.emu.w32(me + 4, struct.unpack('<I', struct.pack('<f', x))[0] if r.random() < 0.8 else _fbits(r))
    c.emu.wbytes(me + 0x18, r.getrandbits(40).to_bytes(5, 'little'))
    return [me]


def _g45aff0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dd060, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4dce50, 1, this=True, ret=r.getrandbits(32))
    o = rnd(c, 0x60)
    for off in (0x40, 0x44, 0x48):
        c.emu.w32(o + off, _fbits(r))
    me = rnd(c, 0x40)
    c.emu.w32(me + 8, o)
    return [me]


S(0x5f4e60, 'GUESS scale a float or report', 'thiscall', None, ret=None, gen=_g5f4e60, note='batch34160')
S(0x4d6150, 'GUESS queue a record', 'thiscall', None, ret=None, gen=_g4d6150, note='batch34160')
S(0x5272e0, 'GUESS integrate and snap to a limit', 'thiscall', None, ret=None, gen=_g5272e0, note='batch34160')
S(0x45aff0, 'GUESS derive radius from a vector', 'thiscall', None, ret=None, gen=_g45aff0, note='batch34160')
