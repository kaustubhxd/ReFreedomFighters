"""specs_s41004.py - t2 () batch 41004: 0x51f930. Slots are recorders; 0x43e920 (x87 vector subtract) runs as exe code; 0x633654 (/GS) is a recorder."""
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


def g51f930(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fl = lambda: _bits(r.choice([r.uniform(-9, 9), r.uniform(-1e4, 1e4), 0.0, 1.0, 1e30, -1e30])) if r.random() < 0.95 else r.choice([NAN, 0x7f800000, r.getrandbits(32)])
    vals = [fl() for _ in range(3)]
    dofill = r.random() < 0.8

    def fill(emu, k):
        if dofill:
            b = emu.arg32(0)
            for i in range(3):
                emu.w32(b + 4 * i, vals[i])
        emu.calllog.append(('fill',))
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    o = obj(c, 0x20, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=fill)}, nslots=0x88 // 4)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=o)})
    me = obj(c, 0x1700, {0x84: pystub(c, 1, this=True, deref={0: 3}), 0x90: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x94 // 4)
    e.w32(me + 0x1654, r.choice([0, 0, r.getrandbits(32) | 1]))
    if r.random() < 0.7:
        for off in (0x1660, 0x1664, 0x1668):
            e.wbytes(me + off, struct.pack('<I', _bits(r.choice([r.uniform(-9, 9), 0.0, 1.0, r.uniform(-1e3, 1e3)]))))
    return [me]


S(0x51f930, 'GUESS compute relative position vector', 'thiscall', None, ret=None, gen=g51f930, nan_heap=True, note='batch41004')
