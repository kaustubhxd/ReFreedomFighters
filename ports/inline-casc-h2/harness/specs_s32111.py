"""specs_s32111.py - h2 () batch 32111: two tier H float / SSE functions. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g584b40(c):
    clear_hooks(c)
    r = c.rng
    ints = [r.choice([0, 1, r.getrandbits(32)]) for _ in range(4)]
    fl = [_f(_fb(r.uniform(-100, 100))) for _ in range(3)]
    ws = [r.getrandbits(32) for _ in range(2)]
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda emu, k: ints[min(k, 3)], side=_log('i'))
    hook_rec(c, 0x4e5e40, 0, this=True, pop=0, ret=lambda emu, k: ws[min(k, 1)], side=_log('w'))
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda emu, k: fl[min(k, 2)], side=_log('f'))
    return [rnd(c, 0x70), rnd(c, 0x20)]


def g575ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x59cb60, 1, this=True, pop=4, side=_log('a'))
    hook_rec(c, 0x561be0, 0, this=True, pop=0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), side=_log('b'))
    hook_rec(c, 0x5ae710, 1, this=True, pop=4, side=_log('c'))
    hook_rec(c, 0x562bc0, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('tail'))
    o = rnd(c, 0x100)
    e.wbytes(o + 0x88, r.choice([struct.pack('<f', r.uniform(-100, 100)), struct.pack('<I', NAN), bytes(4)]))
    so = sysobj(c, table_slots={0x60: pystub(c, 1, ret=(o if r.random() < 0.75 else 0), this=True)})
    e.w32(so + 0x40, r.randrange(0, 100000))
    me = obj(c, 0x230, {0xd0: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('d0'))}, nslots=0xd0 // 4 + 1)
    e.w32(me + 0x94, rnd(c, 0x80))
    return [me]


S(0x584b40, 'GUESS read record fields from source (variant 3)', 'thiscall', None, ret=None, gen=g584b40, note='batch32111')
S(0x575ee0, 'GUESS prime object timers then dispatch', 'thiscall', None, ret='eax', gen=g575ee0, nan_heap=True, note='batch32111')
