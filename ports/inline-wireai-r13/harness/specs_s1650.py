"""specs_s1650.py - residue 13 batch 1650: ZActor::GetMoveFromPos(out). The actor's vslot 0x57c records its arguments
(the first is the stack scratch, skipped). The out vector is a random heap buffer; the byte at +0x726 and +0x64c pick the
copy source."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    me = obj(c, 0x800, {0x57c: stub(c, seq, 2, skip=(0,))})
    c.emu.w8(me + 0x726, r.choice([0, 1, 2, 0x80]))
    c.emu.w32(me + 0x64c, r.choice([0xa, 0xb, 0, r.getrandbits(32)]))
    for off in (0x660, 0x664, 0x668, 0x6e6, 0x6ea, 0x6ee):
        c.emu.w32(me + off, r.getrandbits(32))
    out = rnd(c, 0x10)
    return [me, out]


S(0x478d10, 'ZActor::GetMoveFromPos', 'thiscall', None, ret=None, gen=_gen,
  note='batch1650; scratch argument not recorded; byte +0x726 gate, +0x64c == 0xa picks the other vector')
