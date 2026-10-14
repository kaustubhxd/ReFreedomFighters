"""specs_s35138.py - 0x603d10 (thiscall(list, b) ret 8). list: block with the object array pointer [+0] (4 objects with vtable slot 0 (2 args)) and signed count [+8] (-1, 0 .. 4); this: random 0x20 bytes with the table pointer [+0xc] and the limit [+0x14] (0..5, so the second assert hook runs for i >= limit);
the assert hook at 0x7003b0 is set (random EAX)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g603d10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    objs = [obj(c, 0x10, {0: pystub(c, 2, this=True)}, nslots=2) for _ in range(5)]
    arr = rnd(c, 0x20)
    for i, o in enumerate(objs):
        e.w32(arr + 4 * i, o)
    lst = rnd(c, 0x10)
    e.w32(lst, arr)
    e.w32(lst + 8, r.choice([0xffffffff, 0, 1, 2, 3, 4, 4]))
    me = rnd(c, 0x20)
    e.w32(me + 0xc, rnd(c, 0x40))
    e.w32(me + 0x14, r.randint(0, 5))
    return [me, lst, r.getrandbits(32)]


S(0x603d10, 'GUESS call slot 0 of listed objects with table entries', 'thiscall', None, ret=None, gen=_g603d10, note='batch35138')
