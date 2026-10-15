"""specs_s67514.py - cascade s6 batch 67514 (0x59db90, thiscall(), plain ret). State block at +0x54 (+4 == 1 or not), delegate chain via this slot 0x20 twice, registry at
[0x7003b8] + 0xd8d (count + 0xf4-byte entries, entry +0x34 = owner object; found, not found, and full at 0x20), the owner's record chain (+8, slot 0x50 with an out pointer scripted to
walk a list), 0x4db9a0 / 0x5889c0 / 0x589710 / 0x5898c0 hooks (stack pointers as markers), logger at 0x700390 (slot 0x30)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g59db90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x30: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    nrec = r.choice([0, 1, 2, 3, 4])
    recs = [rnd(c, 0x20) for _ in range(nrec)]
    st = {'i': 0}

    def s50(em, k):
        st['i'] += 1
        em.w32(em.arg32(0), recs[st['i']] if st['i'] < nrec else 0)
    edi = obj(c, 0x40, {0x50: pystub(c, 1, this=True, stackmark=(0,), side=s50)})
    _w(c, edi + 8, recs[0] if recs else 0)
    d1 = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=edi)})
    count = r.choice([0, 1, 2, 5, 0x1f, 0x20])
    G = rnd(c, 0x2800)
    lst = G + 0xd8d
    _w(c, lst, count)
    for i in range(count):
        _w(c, lst + 4 + 0xf4 * i + 0x34, r.getrandbits(32))
    if count and r.random() < 0.4:
        _w(c, lst + 4 + 0xf4 * r.randrange(count) + 0x34, edi)
    _w(c, 0x7003b8, G)
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100]))
    hook_rec(c, 0x5889c0, 1, this='mark')
    hook_rec(c, 0x589710, 1, this=True, stackmark=(0,))
    hook_rec(c, 0x5898c0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100]))
    sb = rnd(c, 0x10)
    _w(c, sb + 4, r.choice([1, 1, 1, 0, 2]))
    t = obj(c, 0x930, {0x20: pystub(c, 0, this=True, ret=d1)})
    _w(c, t + 0x54, sb)
    return [t]


S(0x59db90, 'GUESS bind_registry_entry', 'thiscall', None, ret=None, gen=_g59db90, note='batch67514')
