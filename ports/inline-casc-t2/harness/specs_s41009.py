"""specs_s41009.py - t2 (Sonnet) batch 41009: 0x4486f0, 0x4557c0. Small vector helpers run as exe code; 0x4dc630, 0x4dbe30, 0x633654 and slots are recorders."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _fl(r):
    if r.random() < 0.04:
        return r.choice([NAN, 0x7f800000, r.getrandbits(32)])
    return _bits(r.choice([r.uniform(-9, 9), r.uniform(-1e3, 1e3), 0.0, 1.0, -1.0, 1e-5, 1e-3, 0.5]))


def _mblock(c, r, size=0x90):
    m = rnd(c, size)
    e = c.emu
    for off in (0x30, 0x34, 0x38, 0x40, 0x44, 0x48, 0x4c):
        e.wbytes(m + off, struct.pack('<I', _fl(r)))
    e.wbytes(m + 0x3c, struct.pack('<I', r.getrandbits(32)))
    return m


def g4486f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    m = _mblock(c, r)
    if r.random() < 0.2:
        e.wbytes(m + 0x6c, bytes(4))
    else:
        e.wbytes(m + 0x6c, struct.pack('<I', r.choice([1, 1, r.getrandbits(32) | 1, 0x80000000])))
    me = rnd(c, 0x60)
    e.w32(me + 8, m)
    e.wbytes(me + 0x30, struct.pack('<I', _fl(r)))
    return [me]


def g4557c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    hook_rec(c, 0x4dc630, 2, pop=8, this=True)
    hook_rec(c, 0x4dbe30, 1, pop=4, this=True)
    m = _mblock(c, r)
    sm = _mblock(c, r)
    s = obj(c, 0x20, {}, nslots=1)
    e.w32(s + 8, sm)
    ret_e = r.getrandbits(32)
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=ret_e)})
    me = obj(c, 0x60, {0x20: pystub(c, 0, this=True, ret=s)}, nslots=0x24 // 4)
    e.w32(me + 8, m)
    return [me]


S(0x4486f0, 'GUESS fit bounding sphere', 'thiscall', None, ret=None, gen=g4486f0, nan_heap=True, note='batch41009')
S(0x4557c0, 'GUESS copy bounds from sibling', 'thiscall', None, ret=None, gen=g4557c0, nan_heap=True, note='batch41009')
