"""specs_s67567.py - cascade s6 batch 67567 (0x482370, thiscall() plain ret, return value unused). Flags +0x5fe (lock) and +0x412 (active); slot 0x20 returns an object whose +8 record has +0x3c with bit
0x800 or not; the slots 0x5ec / 0x604 / 0x348 (0 args), 0x59c (2), 0x61c / 0x600 (4), 0x5f0 (2) are recorders (custom stubs: 0x59c writes the first two buffers, 0x61c the last two, 0x600 the first; every call logs the buffers' contents so swapped arguments show); 0x465fb0 / 0x482b80 / 0x441730 / 0x440530 are hooks."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g482370(c):
    clear_hooks(c)
    r = c.rng
    rec = rnd(c, 0x60)
    _w(c, rec + 0x3c, r.choice([0, 0x800, 0x1, 0xfff, 0x7ff]))
    cur = rnd(c, 0x20)
    _w(c, cur + 8, rec)
    e = c.emu
    sizes = {0x59c: (36, 12), 0x61c: (36, 12, 36, 12), 0x600: (36, 12, 36, 12), 0x5f0: (36, 12)}
    logs = {0x59c: (), 0x61c: (0, 1), 0x600: (0, 1, 2, 3), 0x5f0: (0, 1)}
    tag = {'n': 0}

    def mk(slot, writes):
        def h(em, res_):
            tag['n'] += 1
            n = len(sizes[slot])
            args = [em.arg32(i) for i in range(n)]
            em.calllog.append((hex(slot), tuple(em.rbytes(args[i], sizes[slot][i]) for i in logs[slot])))
            for i in writes:
                em.wbytes(args[i], bytes((tag['n'] * 37 + i * 11 + j) & 0xff for j in range(sizes[slot][i])))
            em.ret(eax=0, argbytes=4 * n)
        return e.stub_fn('recorder', h)
    t = obj(c, 0x610, {0x20: pystub(c, 0, this=True, ret=cur), 0x5ec: pystub(c, 0, this=True), 0x604: pystub(c, 0, this=True),
                       0x348: pystub(c, 0, this=True), 0x59c: mk(0x59c, (0, 1)),
                       0x61c: mk(0x61c, (2, 3)), 0x600: mk(0x600, ()),
                       0x5f0: mk(0x5f0, ())})
    _w(c, t + 0x5fe, r.choice([0, 0, 0, 1]), 1)
    _w(c, t + 0x412, r.choice([0, 1, 1, 1]), 1)
    hook_rec(c, 0x465fb0, 0, this=True)
    hook_rec(c, 0x482b80, 0, this=True)
    hook_rec(c, 0x441730, 0, this=True)
    hook_rec(c, 0x440530, 0, this=True)
    return [t]


S(0x482370, 'GUESS update_camera', 'thiscall', None, ret=None, gen=_g482370, note='batch67567')
