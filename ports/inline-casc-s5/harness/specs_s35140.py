"""specs_s35140.py - 0x5f4a00 (thiscall(a) ret 4, ret='eax'). this: random 0xb0 bytes with word [+0xaa], limits [+0x3c] / [+0x30] (0..0x40), table pointers [+0x34] / [+0x28] (heap words); a with bit 0x4000 in half the cases; low word values small and negative-as-s16 included;
the assert hook at 0x7003b0 is set (random EAX)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g5f4a00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    me = rnd(c, 0xb0)
    e.wbytes(me + 0xaa, r.choice([0, 1, 5, 0x20, 0xffff, r.getrandbits(16)]).to_bytes(2, 'little'))
    e.w32(me + 0x3c, r.choice([0, 1, 8, 0x40, r.getrandbits(32)]))
    e.w32(me + 0x30, r.choice([0, 1, 8, 0x40, 0x10000, r.getrandbits(32)]))
    low = r.choice([0, 1, 3, 7, 0x3fff & r.getrandbits(14), 0x8000 | r.getrandbits(15), 0xffff, 0xfffe])
    hi = r.getrandbits(16) << 16 if r.random() < 0.3 else 0
    a = (low & ~0x4000) | (0x4000 if r.random() < 0.5 else 0) | hi
    if a & 0x4000 and r.random() < 0.4:
        w = int.from_bytes(bytes(e.rbytes(me + 0xaa, 2)), 'little')
        sl = (a & 0xffff) - 0x10000 if a & 0x8000 else (a & 0xffff)
        e.w32(me + 0x3c, (w + sl) & 0xffffffff)
    return [me, a]


S(0x5f4a00, 'GUESS index tagged id into two tables', 'thiscall', None, ret='eax', gen=_g5f4a00, note='batch35140')
