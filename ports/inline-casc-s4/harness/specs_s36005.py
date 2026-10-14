"""specs_s36005.py - cascade s4 batch 36005: 0x5370d0 (find table entry by name through slot 0x1e8 and wildcard match 0x4cc850 (hooked, fastcall))."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g5370d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seq = [r.choice([0, 1, 2]) for _ in range(8)]
    st = {'i': 0}

    def h(em, rr):
        em.calllog.append(('match', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=seq[min(st['i'], 7)], argbytes=0)
        st['i'] += 1
    e.hook(0x4cc850, h)
    base = rnd(c, 0x60)
    n = r.choice([0, 1, 2, 3, r.randint(0, 4)])
    tab = rnd(c, 0x20)
    e.wbytes(tab + 8, (n | (r.getrandbits(16) << 16 if r.random() < 0.3 else 0)).to_bytes(4, 'little'))
    e.w32(tab + 0x10, 0 if r.random() < 0.08 else 0x10)
    for i in range(4):
        e.w32(base + 0x10 + 4 * i, 0 if r.random() < 0.12 else r.getrandbits(32))
    rets = [0 if r.random() < 0.15 else r.getrandbits(32) | 1 for _ in range(4)]
    vt = obj(c, 0x10, {0x1e8: pystub(c, 1, this=True, ret=lambda em, k: rets[min(k, 3)])})
    me = e.alloc(0x5320, 4)
    e.w32(me, e.r32(vt))
    e.wbytes(me + 0x5302, (0 if r.random() < 0.1 else base).to_bytes(4, 'little'))
    return [me, 0 if r.random() < 0.08 else tab, 0 if r.random() < 0.08 else rnd(c, 0x10)]


S(0x5370d0, 'GUESS find table entry by name', 'thiscall', None, ret='eax', gen=_g5370d0, note='batch36005')
