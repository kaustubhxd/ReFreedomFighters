"""specs_s36047.py - cascade s4 batch 36047: 0x495dd0 (allocate a zeroed block from an arena), 0x4db070 (collect nodes from a tree)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, stub_memset


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g495dd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    stub_memset(c)
    hook_rec(c, 0x42ab62, 1, pop=0)
    base = e.alloc(0x300, 16)
    e.wbytes(base, bytes([0x77]) * 0x300)
    t = r.choice([0, 0x10, 0x20, 0x40, 0xffffffff])
    hook_rec(c, 0x4cd9b0, 2, this=True, ret=t)
    Y = rnd(c, 0x20)
    X = rnd(c, 0x20)
    e.w32(X, Y)
    e.w32(X + 4, base + 0x10)
    s = rnd(c, 0x40)
    e.w32(s + 0x18, X)
    g = obj(c, 0x20, {0x2c: pystub(c, 3, this=True), 0x50: pystub(c, 3, this=True)})
    e.w32(0x70038c, g)
    e._image_dirty = True
    n = r.choice([0, 1, 5, 0x10, 0x11, 0x1f, 0x20, 0x30])
    if r.random() < 0.4:
        p = base + 0x100
    else:
        p = 0
    return [s, n, p]


def _g4db070(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ctl(em, rr):
        node = em.reg('ecx')
        buf = em.reg('edx')
        em.calllog.append(('4dac50', node))
        em.wbytes(buf, bytes(((node + i * 7) & 0xff) for i in range(16)))
        em.ret(eax=0x9000 + (node & 0xfff), argbytes=0)
    e.hook(0x4dac50, ctl)
    verdicts = [r.choice([0, 1, 1, 0x100]) for _ in range(8)]
    cnt = [0]

    def ok(em, rr):
        k = cnt[0]
        cnt[0] += 1
        buf = em.arg32(0)
        em.calllog.append(('4dba00', em.reg('ecx'), em.reg('edx'), bytes(em.rbytes(buf, 16))))
        em.ret(eax=verdicts[k % 8], argbytes=4)
    e.hook(0x4dba00, ok)
    flagpool = [0x100000, 0x800000, 0x900000, 0x200002, 0x0, 0x100001, 0x800004, r.getrandbits(32)]

    def mknode(depth):
        n = rnd(c, 0x70)
        if r.random() < 0.15:
            e.w32(n + 0x54, 0)
            x = None
        else:
            x = rnd(c, 0x60)
            y = rnd(c, 0x40)
            f = r.choice(flagpool)
            if depth >= 2 and (f & 0x100000):
                f &= ~0x100000
            e.w32(y + 0x23, f)
            e.w32(x + 0xc, y)
            e.w32(n + 0x54, x)
            kids = []
            if f & 0x100000:
                for _ in range(r.choice([0, 1, 2, 3])):
                    kids.append(mknode(depth + 1))
                for i, k in enumerate(kids):
                    e.w32(k + 0x60, kids[i + 1] if i + 1 < len(kids) else 0)
                e.w32(x + 0x50, kids[0] if kids else 0)
        e.w32(n + 0x68, r.choice([0, 1, 5]))
        e.w32(n + 0x3c, r.choice([0, 0x2c00, 0x400, 0x2000, 0x800, 0x8000, 0x1]))
        return n
    root = mknode(0)
    dest = e.alloc(0x40, 4)
    e.wbytes(dest, bytes([0x55]) * 0x40)
    return [r.choice([0, 1, 2]), dest, r.getrandbits(32), root]


S(0x495dd0, 'GUESS allocate a zeroed block from an arena', 'thiscall', None, ret='eax', gen=_g495dd0, note='batch36047')
S(0x4db070, 'GUESS collect nodes from a tree', 'fastcall', None, ret='eax', gen=_g4db070, note='batch36047')
