"""specs_s35154.py - 0x64cd00 (thiscall, no args, ret=None). this: 0x18300 random bytes with a vtable (slot 0x3c recorded, 0 args); unaligned dword +0x10089 = n (0 in 1/6, else 1..4) children pointers at +0x1008d + 4i; child -> +0xc -> X -> +0xc -> Y with flag dword +0x48 having bit 0x400000
in 1/3; [+0x20] = 0..5 pairs at +0x28 + 8i with first dwords sorted in half of the cases, else random; assert hook set (recorded in the call log)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g64cd00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = obj(c, 0x18300, {0x3c: pystub(c, 0, this=True)}, nslots=0x20)
    n = 0 if r.random() < 1 / 6 else r.randint(1, 4)
    e.wbytes(me + 0x10089, n.to_bytes(4, 'little'))
    for i in range(n):
        y = rnd(c, 0x60)
        e.w32(y + 0x48, (r.getrandbits(32) | 0x400000) if r.random() < 1 / 3 else (r.getrandbits(32) & ~0x400000))
        x = rnd(c, 0x20)
        e.w32(x + 0xc, y)
        ch = rnd(c, 0x20)
        e.w32(ch + 0xc, x)
        e.wbytes(me + 0x1008d + 4 * i, ch.to_bytes(4, 'little'))
    cnt = r.choice([0, 1, 2, 3, 4, 5])
    e.w32(me + 0x20, cnt)
    vals = [r.getrandbits(32) for _ in range(cnt)]
    if r.random() < 0.5:
        vals.sort()
        if vals and r.random() < 0.5:
            vals[-1] = vals[0] if len(vals) > 1 else vals[-1]   # equal neighbours are not an error
    for i, v in enumerate(vals):
        e.w32(me + 0x28 + 8 * i, v)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [me]


S(0x64cd00, 'GUESS reset frame state, find flagged child, assert sorted pairs', 'thiscall', None, ret=None, gen=_g64cd00, note='batch35154')
