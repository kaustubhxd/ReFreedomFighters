"""specs_s34036.py - cascade tier E, batch 34036.
0x47ad60: count 0..12 (10 takes the assert-hook path and writes the 11th entry, overwriting the count itself; 11 and 12 write further out without the hook); the key is an existing one in a third of the cases.
0x492170: logger object at 0x70038c with slot 0x48 (1 arg recorder returning random); this slots 0x1f0 (returns 0, -1 or a positive size) and 0x1f4 (2 args); hooked 0x41e290; the fields +0xae8 / +0xaec start zero or non-zero.
0x496620: s slots 0xc and 0x18 (the latter writes 0..3 ids then -1 through its stack pointer argument); a chain of 0..3 nodes at the engine table's unaligned +0x5d29 with ids at +0x20, next at +0x28 and slot 0x54 recorders;
ids match a node or not."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g47ad60(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    me = rnd(c, 0x100)
    n = r.choice([0, 1, 2, 5, 9, 10, 10, 11, 12, r.randint(0, 12)])
    c.emu.w32(me + 0x50, n)
    keys = [r.getrandbits(32) for _ in range(14)]
    for i in range(14):
        if 4 + 8 * i != 0x50:
            c.emu.w32(me + 4 + 8 * i, keys[i])
    k = keys[r.randrange(min(n, 10))] if (n and r.random() < 0.33) else r.getrandbits(32)
    return [me, k, r.getrandbits(32)]


def _g492170(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x41e290, 1, ret=rnd(c, 0x40), pop=0)
    lg = obj(c, 0x20, {0x48: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)}, nslots=0x50 // 4)
    c.emu.w32(0x70038c, lg)
    me = obj(c, 0xb00, {0x1f0: pystub(c, 0, ret=r.choice([0, 0xffffffff, 8, 0x40, r.getrandbits(32)]), this=True),
                        0x1f4: pystub(c, 2, this=True)}, nslots=0x200 // 4)
    c.emu.w32(me + 0xae8, r.choice([0, 0, 0x20, 0xffffffff, r.getrandbits(32)]))
    c.emu.w32(me + 0xaec, 0 if r.random() < 0.5 else r.getrandbits(32) | 1)
    return [me]


def _g496620(c):
    clear_hooks(c)
    r = c.rng
    nn = r.choice([0, 1, 2, 3])
    ids = [r.getrandbits(32) & 0x7fffffff for _ in range(nn)]
    nodes = [obj(c, 0x40, {0x54: pystub(c, 1, this=True)}, nslots=0x60 // 4) for _ in range(nn)]
    if nn >= 2 and r.random() < 0.4:
        ids[1] = ids[0]   # duplicate id: only the first node of the chain may be poked
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 0x20, ids[i])
        c.emu.w32(nd + 0x28, nodes[i + 1] if i + 1 < nn else 0)
    ni = r.choice([0, 1, 2, 3])
    req = [(ids[r.randrange(nn)] if nn and r.random() < 0.6 else r.getrandbits(31)) for _ in range(ni)] + [0xffffffff]

    def rd(em, k):
        em.w32(em.arg32(0), req[min(k, len(req) - 1)])
    s = obj(c, 0x20, {0xc: pystub(c, 1, this=True), 0x18: pystub(c, 2, this=True, side=rd, stackmark=(0,))}, nslots=0x20 // 4)
    so = sysobj(c, table_size=0x5e00)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.wbytes(tbl + 0x5d29, (nodes[0] if nodes else 0).to_bytes(4, 'little'))
    return [rnd(c, 0x20), s]


S(0x47ad60, 'GUESS insert key/value pair into 10-entry table', 'thiscall', None, ret='al', gen=_g47ad60, note='batch34036')
S(0x492170, 'GUESS lazily query and allocate buffer around logger scope', 'thiscall', None, ret=None, gen=_g492170, note='batch34036')
S(0x496620, 'GUESS read ids from stream and poke matching nodes', 'thiscall', None, ret=None, gen=_g496620, note='batch34036')
