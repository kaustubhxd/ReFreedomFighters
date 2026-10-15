"""specs_s70000.py - t1 batch 70000: four tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000

def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]

def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]

def _fbits(c, lo=-5, hi=5):
    r = c.rng
    return r.choice([_fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), NAN, 0x7f800000, 0xff800000, 0, 0x80000000, 0x7fa00001])

# 0x466b70: reads [this+0x35] (float), [this+0x31] (float), global[0x70039c][0x40] (u32 index)
def g466b70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Create this object with two float fields
    f1 = c.fv(-5, 5) if r.random() > 0.1 else _f(NAN)
    f2 = c.fv(-5, 5) if r.random() > 0.1 else _f(NAN)

    me = rnd(c, 0x40)
    e.wbytes(me + 0x35, _fb(f1).to_bytes(4, 'little'))
    e.wbytes(me + 0x31, _fb(f2).to_bytes(4, 'little'))

    # Set up global table at 0x70039c with an index at [table+0x40]
    table = rnd(c, 0x200)
    idx = r.getrandbits(32)
    e.wbytes(table + 0x40, idx.to_bytes(4, 'little'))
    e.wbytes(0x70039c, table.to_bytes(4, 'little'))

    return [me]

S(0x466b70, 'float_branch_logic', 'thiscall', None, ret='st0', gen=g466b70)
