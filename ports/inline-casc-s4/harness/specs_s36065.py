"""specs_s36065.py - cascade s4 batch 36065: 0x4a44d0 (resolve four named objects), 0x4f20a0 (read a record from a stream), 0x4f5d30 (create and configure a child, variant)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4a44d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = [0]

    def s88(em, rr):
        em.calllog.append(('s88', em.reg('ecx'), em.arg32(0)))
        cnt[0] += 1
        em.w32(em.arg32(1), 0x300 + cnt[0])
        em.ret(0, 8)
    o = obj(c, 0x20, {0x88: e.stub_fn('s88', s88)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x58: pystub(c, 1, this=True, ret=lambda em, k: 0x7000 + 0x10 * k)})
    return [rnd(c, 0x1e0)]


def _g4f20a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x44edd0, 1, this=True)
    cnt = [0]

    def mk(addr):
        def side(em, k):
            ptr = em.arg32(0)
            cnt[0] += 1
            if not (0x20000000 <= ptr < 0x30000000):
                em.w32(ptr, [0, 1, 5, 0x100][cnt[0] % 4])
            else:
                em.w32(ptr, 0x4000 + cnt[0])
        return side
    hook_rec(c, 0x4e12e0, 2, this=True, stackmark=(0,), side=mk(0))
    hook_rec(c, 0x4e11e0, 2, this=True, stackmark=(0,), side=mk(1))
    hook_rec(c, 0x4e14a0, 2, this=True)
    kinds = [r.choice([3, 3, 2, 0, 1, 0x103]) for _ in range(2)]
    hook_rec(c, 0x4e1600, 0, this=True, ret=lambda em, k, _k=kinds: _k[min(k, 1)])
    hook_rec(c, 0x4e1b30, 0, this=True)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: 0x5100 + 0x10 * k)})
    d = obj(c, 0x620, {0x32c: pystub(c, 1, this=True)})
    return [d, rnd(c, 0x20)]


def _g4f5d30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dc630, 2, this=True)
    sub = rnd(c, 0x20)
    ch = obj(c, 0x20, {0x154: pystub(c, 0, this=True), 0x27c: pystub(c, 1, this=True), 0x248: pystub(c, 1, this=True),
                       0x2a0: pystub(c, 1, this=True), 0x284: pystub(c, 1, this=True), 0x158: pystub(c, 0, this=True)})
    e.w32(ch + 8, sub)
    mgr = obj(c, 0x20, {0x294: pystub(c, 4, this=True, ret=ch if r.random() < 0.85 else 0)})
    bobj = rnd(c, 0x20) if r.random() < 0.85 else 0
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=bobj)})
    d = rnd(c, 0x90)
    s = e.alloc(16, 4)
    e.wbytes(s, (b'%' if r.random() < 0.5 else b'x') + b'name\0' + bytes(8))
    return [d, mgr, s, r.getrandbits(32)]


S(0x4a44d0, 'GUESS resolve four named objects', 'thiscall', None, ret=None, gen=_g4a44d0, note='batch36065')
S(0x4f20a0, 'GUESS read a record from a stream (3)', 'thiscall', None, ret=None, gen=_g4f20a0, note='batch36065')
S(0x4f5d30, 'GUESS create and configure a child (variant)', 'thiscall', None, ret='eax', gen=_g4f5d30, note='batch36065')
