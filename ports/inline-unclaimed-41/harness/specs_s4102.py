"""specs_s4102.py - unclaimed-41 batch 2 (residue 13): ZFFActorIf::collectOpaqueInfo (0x55ebd0, thiscall, one stack argument, ret 4).

The base collect 0x5095b0 is a checksum stub (GUESS: its effects are not modelled; it takes one stack argument, ret 4). The
object's vtable slot +0x38 (no arguments) returns a random eax. The buffer's vtable slot 0 takes the value (one argument,
callee pops). Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _collect(c):
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1])
    ss.patch(c, 0x5095b0, s)
    vt_t = c.emu.alloc(0x400, 4)
    s, _, _ = hs.stub(c, 0, ecx=True, edx=False, ret=c.rng.getrandbits(32))
    c.emu.w32(vt_t + 0x38, s)
    t = _rnd(c, 0x100)
    c.emu.w32(t, vt_t)
    vt_b = c.emu.alloc(0x100, 4)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1])
    c.emu.w32(vt_b, s)
    buf = _rnd(c, 0x80)
    c.emu.w32(buf, vt_b)
    return [t, buf]


S(0x55ebd0, 'ZFFActorIf::collectOpaqueInfo (unknown) thiscall', 'thiscall', None, ret=None, gen=_collect,
  note='unclaimed-41 batch 2; base collect 0x5095b0 is a checksum stub (GUESS)')
