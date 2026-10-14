"""specs_u69_75.py - area 69, group 75 (slice 8): six small functions. GUESS stubs: 0x4db1b0 (ret 8) and 0x4db670 (ret 4), which the thunks
0x45edc0 and 0x45f040 jump to; they log ECX as a boolean against the object and their args (small ints). 0x5efdf0 runs as real code."""
from pilot import S, F
from ckit import rnd
import struct


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _thunk_a(c):
    e = c.emu
    obj = rnd(c, 0x100)
    self_ = rnd(c, 0x700)
    e.w32(self_ + 0x634, obj)
    return [self_]


def _thunk_b(c):
    e = c.emu
    obj = rnd(c, 0x40)
    self_ = rnd(c, 0x40)
    e.w32(self_ + 8, obj)
    a, b = c.rng.getrandbits(16), c.rng.getrandbits(16)
    e.hook(0x4db1b0, lambda e, res: (e.calllog.append(('t4db1b0', int(e.reg('ecx') == obj), e.arg32(0), e.arg32(1))), e.ret(eax=(e.arg32(0) + 7) & 0xffffffff, argbytes=8)))
    return [self_, a, b]


def _thunk_c(c):
    e = c.emu
    obj = rnd(c, 0x40)
    self_ = rnd(c, 0x40)
    e.w32(self_ + 8, obj)
    a = c.rng.getrandbits(16)
    e.hook(0x4db670, lambda e, res: (e.calllog.append(('t4db670', int(e.reg('ecx') == obj), e.arg32(0))), e.ret(eax=(e.arg32(0) * 3) & 0xffffffff, argbytes=4)))
    return [self_, a]


def _store_floats(c):
    return [rnd(c, 0x40), F(_f32(c.rng.uniform(-300.0, 300.0))), F(_f32(c.rng.uniform(-300.0, 300.0)))]


def _flag(c):
    return [rnd(c, 0x80), c.rng.choice([0, 1, 2, 0x80000000, c.rng.getrandbits(32)])]


def _walk(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x40)
    nodes = [rnd(c, 0x40) for _ in range(r.randrange(0, 5))]
    for i, nd in enumerate(nodes):
        e.w32(nd + 0x30, nodes[i + 1] if i + 1 < len(nodes) else 0)
    e.w32(self_ + 0x24, nodes[0] if nodes else 0)
    return [self_, r.randrange(0, 7)]


S(0x5a8500, 'thunk5a8500 (thiscall, no args, void)', 'thiscall', None, ret=None, gen=_thunk_a, note='u69 group 75; jumps to 0x5efdf0 (real code)')
S(0x45edc0, 'thunk45edc0 (thiscall, two args, ret 8)', 'thiscall', None, ret='eax', gen=_thunk_b, note='u69 group 75; GUESS stub 0x4db1b0')
S(0x45f040, 'thunk45f040 (thiscall, one arg, ret 4)', 'thiscall', None, ret='eax', gen=_thunk_c, note='u69 group 75; GUESS stub 0x4db670')
S(0x4895c0, 'setFloats4895c0 (thiscall, two float args, ret 8)', 'thiscall', None, ret=None, gen=_store_floats, note='u69 group 75')
S(0x650e80, 'setFlagFloat650e80 (thiscall, one arg, ret 4)', 'thiscall', None, ret=None, gen=_flag, note='u69 group 75')
S(0x4d1c80, 'walk4d1c80 (thiscall, one arg, ret 4)', 'thiscall', None, ret='eax', gen=_walk, note='u69 group 75')
