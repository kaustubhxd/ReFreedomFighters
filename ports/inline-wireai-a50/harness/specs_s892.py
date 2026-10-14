"""specs_s892.py - gap-band slice, batch 892: 0x41e6d0 (GUESS name Lookup41e6d0), thiscall, one stack arg (key), ret 4, returns eax.
this+4 is an object whose slot +0x14 (called with the key, one argument) answers a bool; its +0x10 word is the mask; this+0x28 is
the table. Keys: zero, a key that passes, and one that fails, drawn at random."""
from pilot import S
from anim_common import rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    verdict = r.random() < 0.6
    mask = r.randint(0, 0xff)              # the table has 256 words: the index stays in range

    def h14(e, rr):
        e.calllog.append(('obj.14', e.arg32(0)))
        e.ret(eax=1 if verdict else 0, argbytes=4)

    obj = vt_object(c, 0x40, {0x14: h14}, nslots=0x20, name='obj')
    e.w32(obj + 0x10, mask)
    self = rnd(c, 0x100)
    e.w32(self + 4, obj)
    table = rnd(c, 0x400)
    e.w32(self + 0x28, table)
    key = r.choice([0, r.getrandbits(32), r.getrandbits(8), 0xffffffff])
    return [self, key]


S(0x41e6d0, 'Lookup41e6d0 (GUESS name)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch892 (band slice)')
