"""specs_s34066.py - cascade escalation batch 34066: vtable tail jumps 0x466630 (slot 0x21c), 0x54dce0 (clears the global byte at 0x713e19, which starts non-zero, and [this+4], then slot 0x18) and 0x474700 (slot 0x4f4).
The slots are recorders (ECX and two stack args recorded, random return); the objects have real vtables."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _thunk(slot):
    def g(c):
        clear_hooks(c)
        r = c.rng
        me = obj(c, 0x40, {slot: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=(slot + 4) // 4)
        return [me, r.getrandbits(32), r.getrandbits(32)]
    return g


def _g54dce0(c):
    clear_hooks(c)
    r = c.rng
    c.emu.wbytes(0x713e19, bytes([r.randrange(1, 256)]))
    me = obj(c, 0x40, {0x18: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x1c // 4)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x466630, 'GUESS vtable tail thunk slot 0x21c', 'thiscall', None, ret='eax', gen=_thunk(0x21c), note='batch34066')
S(0x54dce0, 'GUESS clear global byte and field, tail slot 0x18', 'thiscall', None, ret='eax', gen=_g54dce0, note='batch34066')
S(0x474700, 'GUESS vtable tail thunk slot 0x4f4', 'thiscall', None, ret='eax', gen=_thunk(0x4f4), note='batch34066')
