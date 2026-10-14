"""specs_s38007.py - cascade s8 batch 38007: 0x49a990 (drain a record iterator with logging). Logger object at 0x700390: slot 0x20 is a logging stub that returns a
5-arg-printer stream for lines 0x272/0x277 and a 2-arg-printer stream otherwise (the printers are cdecl recorders). Iterator object (this+0x138, null 15%): slot 0x14 reports
more for a few calls, slot 0x64 walks a random list of records (key at +4, signed; +0 points to an object whose +4 is the type 0/1/2), 0x4c / 0x20 / 0 recorded."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g49a990(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st2 = obj(c, 0x20, {0x2c: pystub(c, 2, pop=0)})
    st5 = obj(c, 0x20, {0x2c: pystub(c, 5, pop=0)})

    def lg(em, res_):
        line = em.arg32(1)
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), line))
        em.ret(eax=st5 if line in (0x272, 0x277) else st2, argbytes=8)
    lo = obj(c, 0x40, {0x20: e.stub_fn('logger', lg)})
    e.w32(0x700390, lo)
    recs = []
    for _ in range(r.randrange(0, 5)):
        o = rnd(c, 0x10)
        e.w32(o + 4, r.choice([0, 1, 1, 2, r.getrandbits(32)]))
        rec = rnd(c, 0x10)
        e.w32(rec, o)
        e.w32(rec + 4, r.choice([0xffffffff, 0, 1, 5, 5, 0x80000000, 0x7fffffff, r.getrandbits(32)]))
        recs.append(rec)
    nmore = r.choice([0, 1, 2, 3])
    seq = []
    for _ in range(12):
        seq.append(r.choice(recs) if recs and r.random() < 0.65 else 0)
    cnt = [0]

    def nxt(em, k):
        return seq[k] if k < len(seq) else 0
    it = obj(c, 0x40, {0x14: pystub(c, 0, this=True, ret=lambda em, k: 1 if k < nmore else 0),
                       0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                       0x64: pystub(c, 1, this=True, stackmark=(0,), ret=nxt),
                       0x20: pystub(c, 1, this=True),
                       0: pystub(c, 1, this=True)})
    me = rnd(c, 0x140)
    e.w32(me + 0x138, it if r.random() > 0.15 else 0)
    return [me]


S(0x49a990, 'GUESS drain record iterator with logging', 'thiscall', None, ret=None, gen=_g49a990, note='batch38007')
