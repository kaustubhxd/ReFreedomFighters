"""specs_s31060.py - batch 31060: vtable / pointer-chasing tail-jump thunks (8 functions).
Each slot (or the 0x5fd120 target) is a recorder that records ECX and 2 stack args and pops 2, so the thunk must leave the stack alone."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _stub(c):
    return pystub(c, 2, ret=c.rng.getrandbits(32), this=True)


def _vt(c, slot):
    vt = c.emu.alloc(slot + 4, 4)
    c.emu.wbytes(vt, bytes(c.rng.getrandbits(8) for _ in range(slot + 4)))
    c.emu.w32(vt + slot, _stub(c))
    return vt


def _args(c, me):
    return [me, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def direct(slot):
    def g(c):
        clear_hooks(c)
        return _args(c, obj(c, 0x40, {slot: _stub(c)}))
    return g


def g4234e0(c):
    clear_hooks(c)
    me = rnd(c, 0x2200)
    c.emu.w32(me + 0x2191, _vt(c, 4))      # vtable pointer lives at this+0x2191 (unaligned)
    return _args(c, me)


def g5f23f0(c):
    clear_hooks(c)
    hook_rec(c, 0x5fd120, 2, ret=c.rng.getrandbits(32), pop=0, this=True)
    me, mid, inner = rnd(c, 0x40), rnd(c, 0x40), rnd(c, 0x40)
    c.emu.w32(me + 0xc, mid)
    c.emu.w32(mid + 4, inner)
    return _args(c, me)


def g614ee0(c):
    clear_hooks(c)
    me = rnd(c, 0x40)
    c.emu.w32(me + 4, obj(c, 0x40, {0xc: _stub(c)}))
    return _args(c, me)


def indirect_bd(slot):
    def g(c):
        clear_hooks(c)
        me = rnd(c, 0xd0)
        c.emu.w32(me + 0xbd, obj(c, 0x40, {slot: _stub(c)}))   # unaligned
        return _args(c, me)
    return g


S(0x483de0, 'GUESS vtable tail thunk slot 0x59c', 'thiscall', None, ret='eax', gen=direct(0x59c), note='batch31060')
S(0x4234e0, 'GUESS subobject(+0x2191) vtable tail thunk slot 4', 'thiscall', None, ret='eax', gen=g4234e0, note='batch31060')
S(0x461970, 'GUESS vtable tail thunk slot 0x23c', 'thiscall', None, ret='eax', gen=direct(0x23c), note='batch31060')
S(0x4f90b0, 'GUESS vtable tail thunk slot 0x374', 'thiscall', None, ret='eax', gen=direct(0x374), note='batch31060')
S(0x5f23f0, 'GUESS this->[0xc]->[4] tail call 0x5fd120', 'thiscall', None, ret='eax', gen=g5f23f0, note='batch31060')
S(0x614ee0, 'GUESS this->[4] vtable tail thunk slot 0xc', 'thiscall', None, ret='eax', gen=g614ee0, note='batch31060')
S(0x64fac0, 'GUESS this->[0xbd] vtable tail thunk slot 0x2c', 'thiscall', None, ret='eax', gen=indirect_bd(0x2c), note='batch31060')
S(0x64fd60, 'GUESS this->[0xbd] vtable tail thunk slot 0x48', 'thiscall', None, ret='eax', gen=indirect_bd(0x48), note='batch31060')
