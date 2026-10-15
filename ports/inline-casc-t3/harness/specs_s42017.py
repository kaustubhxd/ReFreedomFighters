"""specs_s42017.py - Sonnet t3 batch 42017. 0x494870: engine object 0x70039c with +0x1a9f -> helper (slots 0xb0, 0xac, no args), floats +0x9c7 / +0x9c3 (zero in a third of the cases each),
engine slots 0x1c8 (2 args, callee pops 8, returns eax and edx), 0x178 and 0x17c (3 args, callee pops 12)."""
import struct
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g494870(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ed = r.getrandbits(32)

    def side(em, k):
        em.mu.reg_write(REGS['edx'], ed)
    helper = obj(c, 0x20, {0xb0: pystub(c, 0, this=True), 0xac: pystub(c, 0, this=True)})
    so = sysobj(c, slots={0x1c8: pystub(c, 2, ret=r.getrandbits(32), side=side), 0x178: pystub(c, 3), 0x17c: pystub(c, 3)})
    e.wbytes(so + 0x1a9f, struct.pack('<I', helper if r.random() < 0.9 else 0))
    for off in (0x9c7, 0x9c3):
        e.wbytes(so + off, struct.pack('<f', r.choice([0.0, 0.0, 1.0, r.uniform(-5, 5), float('nan')])))
    return []


S(0x494870, 'GUESS begin/end pair with logging', 'cdecl', None, ret=None, gen=g494870, note='batch42017')
