"""specs_s41011.py - t2 (Sonnet) batch 41011: 0x4fbd50. Engine table slot 0x58 and the object slots are recorders; /GS hook keeps EAX like the real check."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _bits(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g4fbd50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda emu, k: emu.reg('eax'), side=_log('gs'))
    vals = [_bits(r.choice([r.uniform(-9, 9), 0.0, 1.0, 1e30])) if r.random() < 0.9 else r.getrandbits(32) for _ in range(3)]
    dofill = r.random() < 0.8

    def fill(emu, k):
        if dofill:
            b = emu.arg32(0)
            for i in range(3):
                emu.w32(b + 4 * i, vals[i])
        emu.calllog.append(('fill',))
    res = r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)])
    a = obj(c, 0x20, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=fill)}, nslots=0x88 // 4)
    b = obj(c, 0x20, {0x8c: pystub(c, 1, this=True, deref={0: 3}), 0x180: pystub(c, 2, this=True, deref={0: 3}, ret=res)}, nslots=0x184 // 4)
    ra = a if r.random() < 0.9 else 0
    rb = b if r.random() < 0.9 else 0
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda emu, k: (ra, rb)[min(k, 1)])})
    me = rnd(c, 0x80)
    return [me]


S(0x4fbd50, 'GUESS test line between two objects', 'thiscall', None, ret='al', gen=g4fbd50, nan_heap=True, note='batch41011')
