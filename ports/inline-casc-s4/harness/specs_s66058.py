"""specs_s66058.py - cascade s4 batch 66058: 0x41efb0 (/GS-protected: dump a list of slot records as text lines)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, reftab_vt


def _g41efb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))
    n = r.choice([0, 1, 2, 3])
    recs = []
    for _ in range(n):
        rec = e.alloc(0x20, 8)
        arr = e.alloc(0xc8, 8)
        for i in range(0x32):
            e.w32(arr + 4 * i, r.choice([0, 0, 1, 7]))
        e.w32(rec, r.getrandbits(32))
        e.w32(rec + 4, r.getrandbits(32))
        e.w32(rec + 8, r.getrandbits(32))
        e.w32(rec + 0xc, arr)
        recs.append(rec)
    base = reftab_vt(c, recs)

    def pr(em, rr):                       # L->slot 0x184 cdecl (L, a, edi, fmt, ...)
        fmt = em.arg32(3)
        if fmt == 0x677340:
            extra = (em.arg32(4),)
        elif fmt == 0x677360:
            extra = (em.arg32(4), em.arg32(5))
        else:
            extra = (bytes(em.rbytes(em.arg32(4), 0x33)),)
        em.calllog.append(('print', em.arg32(1), em.arg32(2), fmt) + extra)
        em.ret(eax=0, argbytes=0)
    L = obj(c, 0x30, {0x184: e.stub_fn('print', pr)})
    from recruits_util import pystub
    sysobj(c, slots={0x190: pystub(c, 0, this=True, ret=L)})
    vt = e.alloc(0x100, 4)
    for off in (0x4c, 0x64):
        e.w32(vt + off, int.from_bytes(bytes(e.rbytes(base + off, 4)), 'little'))
    lst = e.alloc(0x20, 8)
    e.w32(lst, vt)
    t = e.alloc(0x40, 8)
    e.w32(t + 0x20, 0 if r.random() < 0.15 else lst)
    return [t, r.choice([0, 1, 0x7ffffffe, 0xffffffff])]


S(0x41efb0, 'GUESS /GS dump slot records as text lines', 'thiscall', None, ret=None, gen=_g41efb0, note='batch66058')
