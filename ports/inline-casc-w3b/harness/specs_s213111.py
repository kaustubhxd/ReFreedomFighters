"""specs_s213111.py - batch 213111: tile grid builder (ceil divisions, saturating size, cells filled per tile), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def tdiv(a, b):
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b > 0) else -q


def g5d8a50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    tile = r.choice([1, 2, 3, 4, 5, 8, 16, 17, 32, 64])
    b = r.choice([1, 2, 3, 5, 7])
    a = tile * b + r.randrange(b)
    W = r.choice([0, 1, tile, tile * 3, tile * 3 + 1, r.randrange(0, 120), r.randrange(0, 40) * tile, 64, 128])
    H = r.choice([0, 1, tile, tile * 2, tile * 2 + 1, r.randrange(0, 120), r.randrange(0, 40) * tile, 64])
    off = r.choice([0, 0, 1, -1, tile, -tile, r.randrange(-40, 40), -H - tile * 3, -H - 100, 5 * tile])
    cols = tdiv(W, tile) + (1 if W % tile else 0)
    rows = tdiv(H + off, tile) + (1 if H % tile else 0)
    if cols > 40 or rows > 40:
        return None
    ncell = max(cols, 0) * max(rows, 0)
    this = rnd(c, 0x60)
    e.w32(this + 0x2c, a)
    e.w32(this + 0x30, b)
    e.w32(this + 0x3c, off & 0xffffffff)
    e.wbytes(this + 0x38, struct.pack('<f', r.choice([0.0, 1.0, 0.5, r.uniform(-2, 2)])))
    # allocations (hook returns preallocated buffers)
    cells = e.alloc(max(ncell, 1) * 40 + 16, 4)
    e.wbytes(cells, bytes(r.getrandbits(8) for _ in range(max(ncell, 1) * 40 + 16)))
    hdr = e.alloc(16, 4)
    e.wbytes(hdr, bytes(r.getrandbits(8) for _ in range(16)))
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda emu, k: cells if k == 0 else hdr)
    # engine
    G0 = rnd(c, 0x40)
    def s130(emu, k):
        emu.calllog.append(('w4', bytes(emu.rbytes(emu.arg32(1), 16))))
        emu.w32(emu.arg32(0), r.getrandbits(32))
    Co = obj(c, 0x20, {0x130: pystub(c, 2, this=True, nullflag=(1,), side=s130)}, nslots=0x60)
    e.w32(G0 + 0x18, Co)
    eng = obj(c, 0x1b00, {}, nslots=4)
    e.w32(eng + 0x6f, W)
    e.w32(eng + 0x73, H)
    e.w32(eng + 0x1aa3, G0)
    e.w32(0x70039c, eng)
    # log manager
    def h2c(emu, rr):
        emu.calllog.append(('log', emu.reg('ecx'), emu.arg32(0), emu.arg32(1), emu.arg32(2)))
        emu.ret(eax=0, argbytes=0)
    M = obj(c, 0x20, {0x2c: e.stub_fn('log2c', h2c)}, nslots=0x20)
    Lg = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=M)}, nslots=0x20)
    e.w32(0x700390, Lg)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


def _g(c):
    for _ in range(100):
        a = g5d8a50(c)
        if a is not None:
            return a
    raise RuntimeError('no case')


S(0x5d8a50, 'tile_grid_build', 'thiscall', None, ret=None, gen=_g)
