"""specs_s91001.py - hard trial (fable 2) batch 91001: 0x552b50 script binding (3 ints in, 12 variants out).
ctx = {vtable?, in list, out list}; a list = {array object {variant data, ?, capacity}, offset, count}; the real (verified) helpers
0x5003d0 / 0x5002f0 / 0x602cd0 run on both sides over this data. Input variants are mostly type 0/1 (sometimes 2+ to exercise the
RAISE_EXCEPTION path through the logger at 0x700390 and the assert hook 0x7003b0); output variants mostly 0/2.
[0x7003b8] game object: +0x2c1d -> table (or 0), table+0x5f -> array of 72-byte entries (random), +0x2c25 int.
0x5873a0 (entry lookup, verified elsewhere, 543 bytes) hooked: records (a0, a1, a2), returns -1, 0..3 or a random negative."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, logger


def _list(c, n, types):
    e = c.emu
    off = c.rng.choice([0, 0, 1, 3])
    cap = off + n + c.rng.choice([0, 0, 2])
    data = rnd(c, 8 * cap)
    for i in range(n):
        e.w8(data + 8 * (off + i) + 4, types[i])
    arr = rnd(c, 0x10)
    e.w32(arr, data)
    e.w32(arr + 8, cap)
    lst = rnd(c, 0x10)
    e.w32(lst, arr)
    e.w32(lst + 4, off)
    e.w32(lst + 8, n)
    return lst


def _g552b50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    logger(c, nargs=3)
    bad = r.random() < 0.15
    intypes = [r.choice([0, 1, 1, 1] + ([2, 3, 0xff] if bad else [])) for _ in range(3)]
    outtypes = [r.choice([0, 0, 2, 2, 1] + ([3, 0xff] if bad else [])) for _ in range(12)]
    ctx = rnd(c, 0x10)
    e.w32(ctx + 4, _list(c, 3, intypes))
    e.w32(ctx + 8, _list(c, 12, outtypes))
    g = rnd(c, 0x2c40)
    if r.random() < 0.2:
        e.w32(g + 0x2c1d, 0)
    else:
        tab = rnd(c, 0x80)
        e.w32(tab + 0x5f, rnd(c, 72 * 4))
        e.w32(g + 0x2c1d, tab)
    e.w32(0x7003b8, g)
    idx = r.choice([-1, 0, 1, 2, 3, 3, 0x80000000 | r.getrandbits(31)])
    hook_rec(c, 0x5873a0, 3, pop=12, ret=idx & 0xffffffff)
    return [ctx]


S(0x552b50, 'GUESS SDL_binding_GetEntryInfo', 'stdcall', None, ret=None, gen=_g552b50, note='batch91001')
