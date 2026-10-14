"""specs_s36056.py - cascade s4 batch 36056: 0x4efcf0 (claim a free pooled record or allocate through the manager)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab_vt


def _g4efcf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ne = r.choice([0, 1, 2, 3])
    ids = [r.getrandbits(32) | 1 for _ in range(ne)]
    recs = {}
    for i in ids:
        rec = rnd(c, 0x30)
        e.wbytes(rec + 6, (0 if r.random() < 0.4 else r.randint(1, 0xffff)).to_bytes(2, 'little'))
        recs[i] = rec

    def f0c(em, rr):
        em.calllog.append(('M.slot0c', em.arg32(0)))
        em.ret(recs[em.arg32(0)], 4)
    M = obj(c, 0x20, {0xc: e.stub_fn('M0c', f0c), 0x108: pystub(c, 3, this=True, ret=lambda em, k: 0x7000 + k)})
    X = rnd(c, 0x40)
    e.w32(X + 0x18, M)
    so = sysobj(c)
    e.w32(so + 0x1aa3, X)
    lst = rnd(c, 0x40)
    vt = reftab_vt(c, ids)
    e.w32(lst, vt)
    hook_rec(c, 0x4f00f0, 0, ret=lst if (r.random() < 0.9) else 0)
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4efcf0, 'GUESS claim a free pooled record or allocate', 'stdcall', None, ret='eax', gen=_g4efcf0, note='batch36056')
