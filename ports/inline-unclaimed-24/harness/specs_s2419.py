"""specs_s2419.py - decomp area 24, batch 2419: two vtable forwarders that keep the caller's stack argument.
0x4625b0 (GUESS owner): ecx = dword at +0x6c; jmp through slot 0x20 of that object (recorder, one stack argument).
0x5f3230 SaveSerialInfo_t::saveint32(int): ecx = dword at +0x15; jmp through slot 0x44 of that object (recorder,
one stack argument). The targets are recorders; the stack argument is random."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _gen(off, slot):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        o = rnd(c, 0x100)
        t = obj(c, 0x40, {slot: pystub(c, 1)})
        e.w32(o + off, t)
        return [o, r.getrandbits(32)]
    return g


S(0x4625b0, 'GUESS: vtable forwarder (slot 0x20 of +0x6c)', 'thiscall', None, ret=None, gen=_gen(0x6c, 0x20), note='batch2419')
S(0x5f3230, 'SaveSerialInfo_t::saveint32', 'thiscall', None, ret=None, gen=_gen(0x15, 0x44), note='batch2419')
