"""specs_s35040.py - 0x43e850 (thiscall(a, name, v) ret 0xc). Object with vtable slot 0x74 (2 args: the 0x24-byte local compared by content, a recorded); [this+0x44] null in a third; name = random C string of
0..11 characters; 0x634273 and 0x41e290 cdecl recorders (0x41e290 returns a fresh 0x40-byte block, the copied string is compared as memory); 0x4690b0 hooked as a thiscall recorder (ECX = [this+8]); 0x4de7a0 hooked (fills the 0x24-byte local, thiscall)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g43e850(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4690b0, 0, this=True)
    nb = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, pop=0, ret=nb)
    data = bytes(r.getrandbits(8) for _ in range(0x24))

    def h(em, rr):
        em.calllog.append(('4de7a0',))
        em.wbytes(em.reg('ecx'), data)
        em.ret(eax=0)
    e.hook(0x4de7a0, h)
    me = obj(c, 0x60, {0x74: pystub(c, 2, this=True, deref={0: -0x24})}, nslots=0x20)
    if r.random() < 1 / 3:
        e.w32(me + 0x44, 0)
    name = rnd(c, 0x20)
    s = bytes(r.choice(b'abcXYZ019 _') for _ in range(r.randint(0, 11))) + b'\0'
    e.wbytes(name, s)
    return [me, r.getrandbits(32), name, r.getrandbits(32)]


S(0x43e850, 'GUESS set name and value, dispatch event', 'thiscall', None, ret=None, gen=_g43e850, note='batch35040')
