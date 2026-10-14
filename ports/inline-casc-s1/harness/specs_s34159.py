"""specs_s34159.py - tier H. 0x4f84b0: unaligned ints lo/hi at +0x8f/+0x93 (also hi == lo and hi < lo), argument around the range, slot 0x374 (1 arg), ret al. 0x51aaf0: hooked 0x5003d0 (cells, second call), object at [this+0x18] with slot 0x360 (2 args). 0x52cf60: hooked 0x52cea0 (this and arg logged), the destination pre-filled with random bytes, exe constants copied, returns this."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g4f84b0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0xb0, {0x374: pystub(c, 1, this=True)}, nslots=0x378 // 4) if False else None
    vt = c.emu.alloc(0x400, 4)
    c.emu.w32(vt + 0x374, pystub(c, 1, this=True))
    me = rnd(c, 0xb0)
    c.emu.w32(me, vt)
    lo = r.choice([0, 10, -10, 0x7ffffff0, -0x80000000, r.randrange(-1000, 1000)])
    hi = lo + r.choice([0, 1, 5, 100, -5, 0x7fffffff, r.randrange(0, 2000)])
    hi = (hi + 2 ** 31) % 2 ** 32 - 2 ** 31
    c.emu.wbytes(me + 0x8f, (lo & 0xffffffff).to_bytes(4, 'little') + (hi & 0xffffffff).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x9f, r.getrandbits(32).to_bytes(4, 'little'))
    a = r.choice([lo, hi, lo - 1, hi + 1, (lo + hi) // 2, r.randrange(-3000, 3000), r.getrandbits(32) - 2 ** 31])
    return [me, a & 0xffffffff, r.getrandbits(32)]


def _g51aaf0(c):
    clear_hooks(c)
    r = c.rng
    cell0, cell1 = rnd(c, 0x10), rnd(c, 0x10)
    c.emu.w32(cell0, _fbits(r))
    c.emu.w32(cell1, r.choice([0, 0, 1, 0x80000000, r.getrandbits(32)]))
    seq = [cell1, cell0]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: seq[min(k, 1)])
    o = obj(c, 0x20, {0x360: pystub(c, 2, this=True)}, nslots=0x364 // 4)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, o)
    p = rnd(c, 0x10)
    c.emu.w32(p + 4, rnd(c, 0x10))
    return [me, p]


def _g52cf60(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x52cea0, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x80), r.getrandbits(32)]


S(0x4f84b0, 'GUESS range to fraction', 'thiscall', None, ret='al', gen=_g4f84b0, note='batch34159')
S(0x51aaf0, 'GUESS forward cell pair', 'thiscall', None, ret=None, gen=_g51aaf0, note='batch34159')
S(0x52cf60, 'GUESS reset two blocks from constants', 'thiscall', None, ret='eax', gen=_g52cf60, note='batch34159')
