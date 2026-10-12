"""specs_s2409.py - decomp area 24, batch 2409: CAction::ChangeNames(const char*) (0x49fd70), thiscall, ret 4.
The action's vtable slot 0x88 is a recorder (two stack arguments: the name pointer and 0). When the flag at +0x63 is
set, the object at +0x44 gets slot 0x128 (three stack arguments: the word at 0x7002c8, 1 and the object). Both
recorders log their arguments; the word global is random."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o2 = obj(c, 0x100, {0x128: pystub(c, 3)})
    self_ = obj(c, 0x100, {0x88: pystub(c, 2)})
    e.w8(self_ + 0x63, r.choice([0, 1, 1]))
    e.w32(self_ + 0x44, o2)
    e.w16(0x7002c8, r.getrandbits(16))
    name = rnd(c, 16)
    return [self_, name]


S(0x49fd70, 'CAction::ChangeNames', 'thiscall', None, ret=None, gen=_gen, note='batch2409')
