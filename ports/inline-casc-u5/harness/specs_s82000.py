"""specs_s82000.py - tier H. 0x4bf6b0: manage float state with floats at offsets, vcalls."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj

def _f(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]

def _g4bf6b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    so = sysobj(c)

    # Simple vtable object for [sys + 0x9b], slot 0x58
    tab = obj(c, 0x100, {0x58: pystub(c, 2, this=True, ret=rnd(c, 0x100))}, nslots=0x100 // 4)
    e.w32(so + 0x9b, tab)

    # State values
    e.w32(so + 0x40, r.choice([0, 100, 1000]))
    e.wbytes(so + 0x48, struct.pack('<f', _f(r.uniform(0.1, 10.0))))

    # Main object
    me = obj(c, 0x200, {0x68: pystub(c, 2, this=True)}, nslots=0x200 // 4)

    # Flags and fields
    e.wbytes(me + 0x6e, bytes([r.choice([0, 1, 1, 1])]))
    e.w32(me + 0x4a, r.choice([0, 1, 100]))
    e.w32(me + 0x52, r.choice([0, 1]))

    # Floats
    for off in [0x56, 0x5a, 0x5e, 0x62, 0x66, 0x6a]:
        val = r.choice([0.0, _f(r.uniform(-5.0, 5.0))])
        e.wbytes(me + off, struct.pack('<f', val))

    e.wbytes(0x678620, struct.pack('<f', _f(100.0)))

    return [me]

S(0x4bf6b0, 'GUESS manage float state', 'thiscall', None, ret=None, gen=_g4bf6b0, note='batch82000')
