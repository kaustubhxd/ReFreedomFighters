"""specs_s2406.py - decomp area 24, batch 2406: ZDiscoMove::Save(ZSaveGame*) (0x4ca570), thiscall, ret 4.
The saver is an object whose slots 0x68 (write a block by address), 0x60 (write a byte) and 0x3c (write a dword) are
recorders. The disco-move object is random; slot 0x68 records the three dwords at the block address."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _gen(c):
    clear_hooks(c)
    f = rnd(c, 0x100)
    sg = obj(c, 0x40, {0x68: pystub(c, 1, deref={0: 3}),
                       0x60: pystub(c, 1),
                       0x3c: pystub(c, 1)})
    return [f, sg]


S(0x4ca570, 'ZDiscoMove::Save', 'thiscall', None, ret=None, gen=_gen, note='batch2406')
