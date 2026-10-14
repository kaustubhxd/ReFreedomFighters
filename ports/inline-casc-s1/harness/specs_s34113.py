"""specs_s34113.py - cascade tier E, batch 34113.
0x42cc60: assert hook word 0x7003b0 is a recorder stub; base B (unaligned +0x1b55) null in a tenth; block header word and 0x5a sentinel correct in about two thirds; hooked 0x4ce1c0.
0x43ab30: container object at the unaligned +0x19 with slot 0x4c (writes the iterator) and slot 0x5c (returns the next item and counts the iterator down); items r = block+4 with [r] zero in 60%.
0x445d50: n 0..4 (1 often), arr values small, slot 0x288 returns one of them or a stranger, [this+0x18] current."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _g42cc60(c):
    clear_hooks(c)
    _assert_hook(c)
    r = c.rng
    hook_rec(c, 0x4ce1c0, 2, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x1b60)
    B = rnd(c, 0xa100)
    size = r.choice([4, 8, 16, 0x20, 0x100, 0x120])
    placement = r.choice(['early', 'early', 'start', 'edge', 'edge1', 'late'])
    off = {'early': r.randrange(2, 0x60, 2), 'start': 0, 'edge': 0xa000 - size, 'edge1': 0xa000 - size + 2, 'late': 0x9100}[placement]
    s = B + off
    p = s + 2
    c.emu.wbytes(s, size.to_bytes(2, 'little'))
    c.emu.wbytes(s + size - 1, bytes([0x5a if r.random() < 0.7 else r.getrandbits(8)]))
    mode = r.random()
    if mode < 0.1:
        base = 0
    elif mode < 0.2:
        base = B + off + 4   # s below the base
    elif mode < 0.3:
        base = B - 0xa000 + off + size - 2   # s + size above the end
    else:
        base = B
    c.emu.wbytes(me + 0x1b55, base.to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x1b51, rnd(c, 0x20).to_bytes(4, 'little'))
    return [me, p]


def _g43ab30(c):
    clear_hooks(c)
    r = c.rng
    items = []
    for i in range(r.choice([0, 1, 2, 3])):
        blk = rnd(c, 0x40)
        rr = blk + 4
        c.emu.w32(rr, 0 if r.random() < 0.6 else r.getrandbits(32) | 1)
        items.append(rr if r.random() > 0.2 else 0)
    state = {'k': 0}

    def begin(em, k):
        em.w32(em.arg32(0), 1 if items else 0)

    def nxt(em, k):
        it = em.arg32(0)
        i = state['k'] if k >= 0 else 0
        em.w32(it, 1 if k + 1 < len(items) else 0)

    def nxt_ret(em, k):
        if k == 0:
            return items[0] if items else 0
        return items[k] if k < len(items) else r.choice([0, 0])
    m = obj(c, 0x40, {0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                      0x5c: pystub(c, 1, this=True, side=lambda em, k: em.w32(em.arg32(0), 1 if k + 1 < len(items) else 0),
                                   stackmark=(0,), ret=nxt_ret)}, nslots=0x60 // 4)
    me = rnd(c, 0x30)
    c.emu.wbytes(me + 0x19, (m if r.random() > 0.15 else 0).to_bytes(4, 'little'))
    return [me]


def _g445d50(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 1, 2, 3, 4])
    arr = rnd(c, 0x20)
    vals = [r.randrange(0, 6) for _ in range(n)]
    for i, v in enumerate(vals):
        c.emu.w32(arr + 4 * i, v)
    x = r.choice([0, r.choice(vals) if vals else 0, 9])
    me = obj(c, 0x30, {0x288: pystub(c, 0, ret=x, this=True)}, nslots=0x28c // 4)
    cur = r.choice([0, 0, 9] + vals)
    c.emu.w32(me + 0x18, cur)
    return [me, arr, n]


S(0x42cc60, 'GUESS checked block release', 'thiscall', None, ret=None, gen=_g42cc60, note='batch34113')
S(0x43ab30, 'GUESS iterate and mask flags', 'thiscall', None, ret=None, gen=_g43ab30, note='batch34113')
S(0x445d50, 'GUESS pick current item', 'thiscall', None, ret=None, gen=_g445d50, note='batch34113')
