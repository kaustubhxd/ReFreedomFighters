"""specs_s1143.py - unclaimed-11 batch 44 (slice 10): 0x6563a0 (GUESS), no this use, two stack args (ret 8).
n = (arg2 * 17) * 4 (that is arg2 * 68). If n is nonzero: X = render-manager object's slot 0x20 call (global 0x70039c, +0x190f
object, thiscall rec stub returns X); then X's slot 0x18 is called with (n, arg1) (rec stub, two args). The object here is the
ecx value (not used). All objects are serial_stubs.mkobj with rec stubs (unverified callees, no GC names)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _second_arg_stub(c, ring):
    # thiscall, two stack args: stores the second argument (n) into the heap ring, returns 0 (ret 8).
    b = b'\xb8' + ss.P(ring) + b'\x8b\x4c\x24\x08' + b'\x89\x08' + b'\x31\xc0' + b'\xc2\x08\x00'
    return ss.code(c, b)


def _gen(c):
    ring = c.emu.alloc(8, 4)
    c.emu.wbytes(ring, bytes(8))
    X = ss.mkobj(c, {0x18: _second_arg_stub(c, ring)}, size=0x40)
    holder = ss.mkobj(c, {0x20: ss.rec(c, 0, ret=X)}, size=0x40)
    rm = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(rm, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(rm + 0x190f, holder)
    c.emu.w32(0x70039c, rm)
    c.emu._image_dirty = True
    n = c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(8)])
    return [c.emu.alloc(0x40, 4), c.rng.getrandbits(32), n]


S(0x6563a0, 'GUESS (no name) two-level virtual call sized by arg2*68 thiscall ret 8', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 44 (slice 10)')
