"""specs_s34001.py - cascade escalation batch 34001: tail-jump stubs 0x4f8e10 (this+0x8f, 0x4cc1d0), 0x504870 (vtable 0x69cc88, 0x500a10),
0x51b020 (vtable 0x69f43c, 0x51aa60); 0x473b40 (clear byte +0x3e8); 0x5333d0 (cvttss2si of the unaligned float at +0x87).
Tail targets are recorder hooks (ECX and one stack argument recorded, random return); the objects are random blocks."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _tail(tgt):
    def g(c):
        clear_hooks(c)
        hook_rec(c, tgt, 1, ret=c.rng.getrandbits(32), this=True)
        return [rnd(c, 0x400), c.rng.getrandbits(32)]
    return g


def _g473b40(c):
    clear_hooks(c)
    return [rnd(c, 0x400)]


def _g5333d0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x100)
    k = r.random()
    if k < 0.4:
        v = struct.pack('<f', r.uniform(-1e4, 1e4))
    elif k < 0.6:
        v = struct.pack('<f', r.uniform(-3e9, 3e9))
    elif k < 0.8:
        v = struct.pack('<f', float(r.randint(-5, 5)) + r.choice([0.0, 0.5, 0.99, -0.99]))
    else:
        v = r.getrandbits(32).to_bytes(4, 'little')   # includes NaN / inf / denormals
    c.emu.wbytes(me + 0x87, v)
    return [me]


S(0x4f8e10, 'GUESS this+0x8f tail', 'thiscall', None, ret='eax', gen=_tail(0x4cc1d0), note='batch34001')
S(0x504870, 'GUESS set vtable 0x69cc88 tail', 'thiscall', None, ret='eax', gen=_tail(0x500a10), note='batch34001')
S(0x51b020, 'GUESS set vtable 0x69f43c tail', 'thiscall', None, ret='eax', gen=_tail(0x51aa60), note='batch34001')
S(0x473b40, 'GUESS clear byte +0x3e8', 'thiscall', None, ret=None, gen=_g473b40, note='batch34001')
S(0x5333d0, 'GUESS truncate float +0x87', 'thiscall', None, ret='eax', gen=_g5333d0, note='batch34001')
