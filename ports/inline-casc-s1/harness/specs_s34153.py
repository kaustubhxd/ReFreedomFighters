"""specs_s34153.py - tier H. 0x4f6e00: unaligned floats at +0x9b/+0x9f, two out vectors (sometimes the same or overlapping block). 0x467a40: vector argument, engine float at [0x70039c]+0x48, unaligned float +0x1c6 around the clamp constant 0x678858. 0x483a20: this slot 0x80 (2 args) and the hooked fastcall helper 0x451890 (ecx, edx logged by a side hook). 0x527360: float +0xc around zero, limits at the unaligned +0x21 / +0x1d, integrator at +0x10, engine float [0x70039c]+0x48."""
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
        v = center + r.choice([0.0, 1e-6, -1e-6, 0.01, -0.01, 1.0, -1.0, 100.0, -100.0])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _engf(c, bits):
    so = rnd(c, 0x60)
    c.emu.w32(so + 0x48, bits)
    c.emu.w32(0x70039c, so)


def _g4f6e00(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xb0)
    c.emu.wbytes(me + 0x9b, _fbits(r).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x9f, _fbits(r).to_bytes(4, 'little'))
    p = rnd(c, 0x20)
    k = r.random()
    if k < 0.2:
        q = p
    elif k < 0.3:
        q = p + 4
    elif k < 0.35:
        q = me + 0x98            # overlaps the source floats
        p = rnd(c, 0x20)
    else:
        q = rnd(c, 0x20)
    return [me, q, p]


def _g467a40(c):
    clear_hooks(c)
    r = c.rng
    lim = _const(0x678858)
    _engf(c, _fbits(r))
    me = rnd(c, 0x1d0)
    v = rnd(c, 0x10)
    for i in range(3):
        c.emu.w32(v + 4 * i, r.getrandbits(32))
    c.emu.wbytes(me + 0x1c6, _fbits(r, lim).to_bytes(4, 'little'))
    return [me, v]


def _g483a20(c):
    clear_hooks(c)
    r = c.rng

    def log_edx(em, k):
        em.calllog.append(('edx', em.reg('edx')))
    hook_rec(c, 0x451890, 1, this=True, pop=4, side=log_edx)
    me = obj(c, 0x470, {0x80: pystub(c, 2, this=True)}, nslots=0x84 // 4)
    c.emu.wbytes(me + 0x451, _fbits(r).to_bytes(4, 'little'))
    return [me, rnd(c, 0x40), rnd(c, 0x40)]


def _g527360(c):
    clear_hooks(c)
    r = c.rng
    _engf(c, _fbits(r))
    me = rnd(c, 0x40)
    k = r.random()
    f = r.choice([1.0, -1.0, 0.0, -0.0, 5.0, -5.0, 0.001]) if k < 0.4 else None
    c.emu.w32(me + 0xc, struct.unpack('<I', struct.pack('<f', f))[0] if f is not None else _fbits(r))
    c.emu.w32(me + 0x10, _fbits(r))
    c.emu.wbytes(me + 0x21, _fbits(r).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x1d, _fbits(r).to_bytes(4, 'little'))
    return [me]


S(0x4f6e00, 'GUESS scale two floats into a vector', 'thiscall', None, ret=None, gen=_g4f6e00, note='batch34153')
S(0x467a40, 'GUESS set vector and advance clamped float', 'thiscall', None, ret=None, gen=_g467a40, note='batch34153')
S(0x483a20, 'GUESS forward then accumulate', 'thiscall', None, ret=None, gen=_g483a20, note='batch34153')
S(0x527360, 'GUESS integrate and clamp', 'thiscall', None, ret=None, gen=_g527360, note='batch34153')
