"""specs_s67571.py - cascade s6 batch 67571 (0x6490b0, thiscall(bits, objs, n, owner) ret 0x10, returns eax). n is 0 / 1 / 5 / 16 / 17 / 33 / negative; the 2-bit-per-record array is random; the records
(rnd blocks, word +0x5a in a small key set) map through the slot table at this[0x10071] (zero or a record whose flag byte +5 and object (+8) flag byte +5 vary); 0x64d030 (4 args), 0x63e850 and 0x64c090 are
custom hooks logging every call; sys[0x3c] is a random stamp."""
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g6490b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c)
    keys = [0x11, 0x12, 0x1013, 0xf014, 0x15, 0x811, 0x8a15]
    tab = e.alloc(0x4000, 4)
    e.wbytes(tab, bytes(0x4000))
    for k in set(x & 0xfff for x in keys):
        if r.random() < 0.6:
            s = rnd(c, 0x30)
            o = rnd(c, 0x20)
            _w(c, o + 5, r.choice([0, 1, 2, 0x41]), 1)
            _w(c, s + 5, r.choice([0, 1, 2, 5]), 1)
            _w(c, s + 8, o)
            _w(c, tab + 4 * k, s)

    def l(tag, nargs, retv=0, this=True):
        def h(em, res_):
            em.calllog.append((tag, em.reg('ecx'),) + tuple(em.arg32(i) for i in range(nargs)))
            em.ret(eax=retv, argbytes=4 * nargs)
        return h
    e.hook(0x64d030, l('64d030', 4, 0x7777))
    e.hook(0x63e850, l('63e850', 1))
    e.hook(0x64c090, l('64c090', 1))
    n = r.choice([0, 1, 5, 16, 17, 33, -3])
    bits = e.alloc(0x40, 4)
    e.wbytes(bits, bytes(r.getrandbits(8) for _ in range(0x40)))
    cnt = max(n, 0)
    recs = []
    for _ in range(cnt):
        o = rnd(c, 0x70)
        _w(c, o + 0x5a, r.choice(keys), 2)
        recs.append(o)
    arr = e.alloc(4 * max(cnt, 1) + 4, 4)
    for i, o in enumerate(recs):
        e.w32(arr + 4 * i, o)
    t = rnd(c, 0x10200)
    _w(c, t + 0x10071, tab)
    _w(c, t + 0x1005d, rnd(c, 0x20))
    owner = rnd(c, 0x30)
    return [t, bits, arr, n & 0xffffffff, owner]


S(0x6490b0, 'GUESS attach_records', 'thiscall', None, ret='eax', gen=_g6490b0, note='batch67571')
