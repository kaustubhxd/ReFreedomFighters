"""specs_s36046.py - cascade s4 batch 36046: 0x5fccb0 (replace '/' with the path separator), 0x422ed0 (send five property blocks), 0x444380 (read flags from a stream), 0x48dbd0 (accumulate sizes)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g5fccb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 5, 9, 14])
    chars = [ord('/'), ord('/'), ord('a'), ord('A'), ord('\\'), ord('.'), ord('Z'), ord('0'), ord('o')]
    data = bytes(r.choice(chars) for _ in range(n))
    buf = e.alloc(32, 4)
    e.wbytes(buf, data + bytes([0x55]) * (32 - n))
    s = rnd(c, 0x10)
    e.w32(s, buf)
    e.w32(s + 4, buf + n)
    return [s]


def _g422ed0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    gv = obj(c, 0x20, {0x1c8: pystub(c, 4, this=True, ret=lambda em, k: 0x4000 + k)})
    e.w32(0x70039c, gv)
    e._image_dirty = True
    s = obj(c, 0x1000, {0x1b8: pystub(c, 1, this=True), 0x1fc: pystub(c, 5, this=True)})
    return [s, r.getrandbits(32), r.getrandbits(32)]


def _g444380(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    hook_rec(c, 0x442c30, 1, this=True)
    kinds = [r.choice([3, 3, 2, 0xff, 0, 1, 0x1ff, 0x103]) for _ in range(6)]
    hook_rec(c, 0x4e1600, 0, this=True, ret=lambda em, k, _k=kinds: _k[min(k, 5)])
    vals = [r.choice([0, 1, 5, 0x100]) for _ in range(6)]
    cnt = [0]

    def side(em, k):
        ptr = em.arg32(0)
        if not (0x20000000 <= ptr < 0x30000000):   # stack target: give it a value; heap targets keep their data
            em.w32(ptr, vals[min(cnt[0], 5)])
        cnt[0] += 1
    hook_rec(c, 0x4e12e0, 2, this=True, stackmark=(0,), side=side)
    hook_rec(c, 0x4e1b30, 0, this=True)
    d = obj(c, 0xa0, {0x378: pystub(c, 2, this=True)})
    a = rnd(c, 0x20)
    return [d, a]


def _g48dbd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    ids = [r.getrandbits(32) | 1 for _ in range(4)]
    objs = {}
    for i in ids:
        if r.random() < 0.7:
            o = rnd(c, 0x40)
            e.w32(o + 0x18, r.choice([0, 1, 0x10, 0x11, 0x17, 0x18, 0x20, 0x31, r.getrandbits(8)]))
            objs[i] = o

    def find(em, rr):
        em.calllog.append(('tab.slot158', em.arg32(0)))
        em.ret(objs.get(em.arg32(0), 0), 4)
    sysobj(c, table_slots={0x158: e.stub_fn('find', find)})
    s = obj(c, 0xae0, {0xcc: pystub(c, 0, this=True, ret=r.choice([0, 1, 1, 0x100]))})
    e.w32(s + 0xadc, r.choice([0, 0, 1, 0x80]))
    n = r.choice([0, 1, 2, 3, 4])
    arr = e.alloc(12 * 5, 4)
    for i in range(n):
        e.w32(arr + 12 * i, r.choice(ids))
        e.w32(arr + 12 * i + 4, r.choice([0, 1, 2, 5, 0xffffffff, r.getrandbits(32)]))
        e.w32(arr + 12 * i + 8, r.choice([0, 1, 3, 0xfffffffe, r.getrandbits(32)]))
    A = e.alloc(8, 4)
    B = e.alloc(8, 4)
    e.w32(A, r.getrandbits(32))
    e.w32(B, r.getrandbits(32))
    return [s, A, B, arr, n]


S(0x5fccb0, "GUESS replace '/' with the path separator", 'thiscall', None, ret=None, gen=_g5fccb0, note='batch36046')
S(0x422ed0, 'GUESS send five property blocks', 'thiscall', None, ret=None, gen=_g422ed0, note='batch36046')
S(0x444380, 'GUESS read flags from a stream (variant)', 'thiscall', None, ret=None, gen=_g444380, note='batch36046')
S(0x48dbd0, 'GUESS accumulate sizes of an entry list', 'thiscall', None, ret=None, gen=_g48dbd0, note='batch36046')
