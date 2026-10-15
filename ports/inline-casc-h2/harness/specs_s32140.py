"""specs_s32140.py - h2 (Sonnet) batch 32140: 0x5c87f0, 0x528b60. Callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g5c87f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda emu, k: emu.reg('eax'))
    inner = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), pop=0, side=_log('log2'))}, nslots=0x30 // 4)
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))}, nslots=0x24 // 4)
    e.w32(0x700390, g)

    def fill(emu, k):
        v = emu.arg32(0)
        if r.random() < 0.8:
            for i in range(3):
                emu.w32(v + 4 * i, _bits(r.choice([r.uniform(-300, 300), 0.0, -100.0, 1e30, -1e30])) if r.random() < 0.9 else NAN)
        emu.calllog.append(('fill',))
    tobj = obj(c, 0x20, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=fill)}, nslots=0x88 // 4)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=tobj)})
    hook_rec(c, 0x5c8750, 1, this=True, pop=4, deref={0: 3}, ret=r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32), 0xffffff00]))
    pp = rnd(c, 0x10)
    e.w32(pp, r.choice([0, 0, r.getrandbits(32), 1]))
    return [rnd(c, 0x40), pp]


def g528b60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x2300)
    counts = [0, 1, 2, 3, 4, 5, 6, 0xffffffff, 0x80000000]

    def fv():
        return _bits(r.choice([r.uniform(-9, 9), 0.0, 1.0, 100.0, -3.0])) if r.random() < 0.9 else r.choice([NAN, 0x7f800000, 0])
    for off in (0x21b9, 0x74, 0x78, 0x68, 0x6c):
        e.wbytes(me + off, struct.pack('<I', fv()))
    e.wbytes(me + 0x8d, struct.pack('<I', r.choice(counts)))
    e.wbytes(me + 0x91, struct.pack('<I', r.choice(counts)))

    def side(emu, k):
        if r.random() < 0.15:
            emu.wbytes(me + 0x8d, struct.pack('<I', r.choice([0, 1, 2, 3])))
        if r.random() < 0.15:
            emu.wbytes(me + 0x91, struct.pack('<I', r.choice([0, 1, 2, 3])))
        if r.random() < 0.2:
            emu.wbytes(me + 0x6c, struct.pack('<I', fv()))
        if r.random() < 0.2:
            emu.wbytes(me + 0x7c, struct.pack('<I', fv()))
        emu.calllog.append(('s', k))
    hook_rec(c, 0x529e30, 2, this=True, pop=8, side=side)
    return [me]


S(0x5c87f0, 'GUESS validate and store lookup position', 'thiscall', None, ret='al', gen=g5c87f0, nan_heap=True, note='batch32140')
S(0x528b60, 'GUESS update paired entries', 'thiscall', None, ret=None, gen=g528b60, nan_heap=True, note='batch32140')
