"""specs_s67527.py - cascade s6 batch 67527 (0x65c3e0, thiscall(unused) ret 4). The object holds a record table at +0x28 (8-byte entries: key dword, payload pointer; count word at +0x20, cursor at
+0x24); the slots 0x44 / 0x74 / 0x78 / 0x7c / 0x80 are custom logging stubs (callee pops; byte-valued arguments are logged masked to 8 bits, the original pushes a stack dword whose upper bytes
are garbage). Payloads: +0x14 -> block with a dword at +0x20, +8 an optional pointer."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g65c3e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mk(slot, nargs, mask):
        def h(em, res_):
            a = [em.arg32(i) for i in range(nargs)]
            a = [(x & 0xff) if i in mask else x for i, x in enumerate(a)]
            em.calllog.append(('slot', hex(slot), tuple(a)))
            em.ret(eax=r.getrandbits(32), argbytes=4 * nargs)
        return e.stub_fn('recorder', h)
    slots = {0x44: mk(0x44, 1, ()), 0x74: mk(0x74, 2, (1,)), 0x78: mk(0x78, 1, (0,)), 0x7c: mk(0x7c, 1, (0,)), 0x80: mk(0x80, 2, (1,))}
    n = r.choice([0, 1, 2, 3, 4, 6])
    t = obj(c, 0x28 + 8 * (n + 2), slots)
    _w(c, t + 0x20, n)
    pay = []
    for _ in range(3):
        blk = rnd(c, 0x30)
        _w(c, blk + 0x20, r.getrandbits(32))
        pl = rnd(c, 0x20)
        _w(c, pl + 0x14, blk)
        _w(c, pl + 8, r.choice([0, rnd(c, 0x10)]))
        pay.append(pl)
    pool = [0xffffffff, 0x0, 0x78000000, 0x78000013, 0x08000011, 0x10000021, 0x00000012, 0x08000412, 0x00000019, 0x78000019, 0x18000001, 0x00008011, 0x08000010]
    prev = None
    for i in range(n):
        k = r.choice(pool) if r.random() < 0.8 else r.getrandbits(32)
        if prev is not None and r.random() < 0.2:
            k = prev
        prev = k
        _w(c, t + 0x28 + 8 * i, k)
        _w(c, t + 0x2c + 8 * i, r.choice(pay))
    cur = r.choice([0, 0, 1, 1, 2, 3]) if n else 0
    cur = min(cur, n)
    _w(c, t + 0x24, t + 0x28 + 8 * cur)
    return [t, r.getrandbits(32)]


S(0x65c3e0, 'GUESS dispatch_record_runs', 'thiscall', None, ret='al', gen=_g65c3e0, note='batch67527')
