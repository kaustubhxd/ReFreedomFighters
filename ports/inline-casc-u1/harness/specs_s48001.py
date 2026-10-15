"""specs_s48001.py - tier H. 0x5e3b40: this block with five unaligned embedded sub-objects (vtable pointers at +0x10d/+0x125/+0x13d/+0x155/+0x16d, slots 0x14 / 0xc / 4),
owner P at [this+4] with flag word at +0x417 (unaligned) and slots 0x400 / 0x534, engine object with [+0x40] and random slot 0x1c0 (st0), float cells +0xc and +0x185."""
import struct
import pefile
from pilot import S, EDGE_F
from pe_emu import DEFAULT_EXE
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj

_pe = pefile.PE(DEFAULT_EXE)
_img = _pe.OPTIONAL_HEADER.ImageBase
K678620 = struct.unpack('<f', _pe.get_data(0x678620 - _img, 4))[0]


def _fv(r, lo=-300, hi=300):
    k = r.random()
    if k < 0.1:
        return r.choice(EDGE_F)
    if k < 0.14:
        return struct.unpack('<f', struct.pack('<I', r.getrandbits(32)))[0]
    return r.uniform(lo, hi)


def _fb(x):
    return struct.pack('<f', x)


def _g5e3b40(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    bufs = [em.alloc(8, 4) for _ in range(3)]
    for b in bufs:
        em.wbytes(b, bytes(r.getrandbits(8) for _ in range(8)))
    me = rnd(c, 0x200)
    for off, has4 in ((0x125, 0), (0x155, 0), (0x13d, 0), (0x16d, 0), (0x10d, 1)):
        slots = {0x14: pystub(c, 1, ret=lambda e, k: r.choice([0, 0, bufs[0], bufs[1], bufs[2]]), this=True),
                 0xc: pystub(c, 1, this=True, st0=lambda e, k: _fv(r, -50, 50))}
        if has4:
            slots[4] = pystub(c, 0, this=True)
        vt = c.emu.alloc(0x20, 4)
        for o_, code in slots.items():
            em.w32(vt + o_, code)
        em.wbytes(me + off, vt.to_bytes(4, 'little'))
    P = obj(c, 0x440, {0x400: pystub(c, 1, this=True), 0x534: pystub(c, 0, ret=lambda e, k: r.choice([0, 1, 0x100, 0xff00]), this=True)}, nslots=0x538 // 4)
    flags = 0
    for bit in (0x800, 0x8000000, 0x400, 0x10000000):
        if r.random() < 0.4:
            flags |= bit
    flags |= r.getrandbits(32) & 0x03ffffff & ~0xc00 if r.random() < 0.3 else 0
    em.wbytes(P + 0x417, flags.to_bytes(4, 'little'))
    em.w32(me + 4, P)
    em.wbytes(me + 0xc, _fb(_fv(r, -5, 5)))
    x = _fb(_fv(r, -300, 300))
    em.wbytes(me + 0x185, x)
    so = sysobj(c, rand=lambda e, k: _fv(r, -3, 3))
    lim = r.choice([r.randint(-300, 300), r.randint(-3, 3), r.getrandbits(32)])
    xv = struct.unpack('<f', x)[0]
    if r.random() < 0.35 and abs(xv * K678620) < 1e9:   # lim equal to (or next to) the truncated product
        lim = int(struct.unpack('<f', struct.pack('<f', xv * K678620))[0]) + r.choice([0, 0, 0, 1, -1])
    em.w32(so + 0x40, lim & 0xffffffff)
    out = em.alloc(8, 4)
    em.wbytes(out, bytes(r.getrandbits(8) for _ in range(8)))
    return [me, out, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x5e3b40, 'GUESS pick sub-object by owner flags and advance time', 'thiscall', None, ret='st0', gen=_g5e3b40, nan_heap=True, note='batch48001')
