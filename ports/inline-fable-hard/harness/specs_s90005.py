"""specs_s90005.py - hard trial (fable) batch 90005: 0x552b50 script binding (3 int args -> 12 results). The value-list helpers 0x5003d0 /
0x5002f0 / 0x602cd0 run real on lists {array {data, -, count}, offset, count} of 8-byte typed slots with random types (so their type-check
logging through the logger at 0x700390 and the assert hook is exercised); 0x5873a0 hooked (records the 3 ints, returns an index or -1);
global [0x7003b8] with the manager at +0x2c1d (sometimes null) whose +0x5f array holds 72-byte records with random flags."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, logger


def _assert(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _g552b50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    logger(c, 3)

    def mklist(n, types):
        off = r.choice([0, 0, 1, 4])
        data = rnd(c, 8 * (n + off + 4))
        for i in range(n + off):
            e.wbytes(data + 8 * i + 4, bytes([types[i % len(types)]]))
        arr = rnd(c, 0x10)
        e.w32(arr, data)
        e.w32(arr + 8, n + off + 4)
        lst = rnd(c, 0x10)
        e.w32(lst, arr)
        e.w32(lst + 4, off)
        e.w32(lst + 8, n if r.random() < 0.9 else n - 1)
        return lst
    args = mklist(3, [r.choice([0, 1, 1, 1, 2, 3]) for _ in range(3)])
    res = mklist(12, [r.choice([0, 2, 2, 2, 1, 3]) for _ in range(12)])
    rec = rnd(c, 0x10)
    e.w32(rec + 4, args)
    e.w32(rec + 8, res)
    tbl = e.alloc(0x2c40, 4)
    e.wbytes(tbl + 0x2c10, bytes(r.getrandbits(8) for _ in range(0x30)))
    if r.random() < 0.2:
        e.wbytes(tbl + 0x2c1d, bytes(4))
    else:
        mgr = rnd(c, 0x70)
        base = rnd(c, 72 * 6 + 0x40)
        e.wbytes(mgr + 0x5f, base.to_bytes(4, 'little'))
        e.wbytes(tbl + 0x2c1d, mgr.to_bytes(4, 'little'))
        for i in range(6):
            e.w32(base + 72 * i + 0x34, r.choice([0, 1, 2, 4, 3, 5, 6, 8 | 2, 0x10 | 1, 0x18, 0x1f, r.getrandbits(32)]))
    e.w32(0x7003b8, tbl)
    idx = r.choice([-1, 0, 1, 2, 3, 5, -5, 0, 1])
    hook_rec(c, 0x5873a0, 3, pop=12, ret=idx & 0xffffffff)
    return [rec]


S(0x552b50, 'GUESS script binding: placement record lookup', 'stdcall', None, ret=None, gen=_g552b50, note='batch90005')
