"""specs_s35068.py - 0x5b14b0 (thiscall, no args, ret='eax' = this). this = 0x160 random bytes (every stored field is observable); 0x4de7a0 hooked (thiscall: fills the 0x24-byte local with fixed random bytes);
0x5b1760 hooked (thiscall, four stack args, the 12-byte array and the 36-byte local compared by content)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g5b14b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    data = bytes(r.getrandbits(8) for _ in range(0x24))

    def h(em, rr):
        em.calllog.append(('4de7a0',))
        em.wbytes(em.reg('ecx'), data)
        em.ret(eax=0)
    e.hook(0x4de7a0, h)
    hook_rec(c, 0x5b1760, 4, this=True, deref={2: 3, 3: -0x24})
    return [rnd(c, 0x160)]


S(0x5b14b0, 'GUESS constructor with sub-object tags', 'thiscall', None, ret='eax', gen=_g5b14b0, note='batch35068')
