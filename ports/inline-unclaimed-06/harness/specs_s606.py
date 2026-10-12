"""specs_s606.py - unclaimed-06 claim 6 (docs/20-unclaimed-06.md): ZItemTemplateAmmo::Save(ZSaveGame*).
Thiscall, one argument, ret 4. The ZSaveGame is a stand-in from serial_stubs.save_obj (counting rec stubs on every vtable slot 0x04 to 0x7c, 0x10 with two arguments). The base save 0x441790 is original code on both sides."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import struct
import serial_stubs as ss


def _rec2(c, nargs):
    """Like serial_stubs.rec, but logs the first two arguments of each call (8 calls, 16 dwords per call), so the
    byte count passed to slot 0x10 is compared too. Thiscall with nargs stack arguments, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4)
    c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'        # mov edx, [esp+4]; mov [eax], edx
         + b'\x8b\x54\x24\x08\x89\x50\x04'    # mov edx, [esp+8]; mov [eax+4], edx
         + b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc2' + struct.pack('<H', 4 * nargs))
    return ss.code(c, b)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    self = _rnd(c, 0x1000)
    ss.patch(c, 0x441790, ss.rec(c, 1))   # GUESS-stub of the base save (counts its argument)
    slots = {off: ss.rec(c, 1) for off in range(0x04, 0x80, 4)}
    slots[0x10] = _rec2(c, 2)
    sg = ss.save_obj(c, slots)
    return [self, sg]


S(0x4706d0, 'ZItemTemplateAmmo::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-06 claim 6; base save 0x441790 stubbed (GUESS), four ZSaveGame slots via serial stubs')
