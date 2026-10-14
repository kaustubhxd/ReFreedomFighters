"""specs_s3018.py - unclaimed-30 batch 18 (docs/20-unclaimed-30.md, claim 1): 0x58a8d0 (no name in the name map; fastcall, returns this).
The object's slots (0x40 handle, 0x48 int/float, 0x50 float, 0x6c vector) are logged stubs with values from the call-log position; the
first slot-0x48 call of a run writes the entry count. The message table's slot 0x58 returns one object per handle. The out array holds
the count dword and up to three 48-byte records. No faulting cases."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable, sf


def _col(c):
    e = c.emu
    r = c.rng
    n = r.randint(0, 3)
    vals = [sf(c.fv(-200, 200)) for _ in range(32)]
    ints = [r.getrandbits(16) for _ in range(32)]
    m_obj = rnd(c, 0x40)
    handles = [r.getrandbits(16) for _ in range(4)]

    def slot48(em, a):
        # the call log already has this call: the first slot-0x48 call of the run is the one with k == 1
        k = sum(1 for t in em.calllog if t[0] == 'col' and t[1] == 0x48)
        if k == 1:
            em.w32(a[0], n)
        elif k % 2:
            em.wf32(a[0], vals[k % 32])
        else:
            em.w32(a[0], ints[k % 32])
        return 0

    def slot50(em, a):
        em.wf32(a[0], vals[len(em.calllog) % 32])
        return 0

    def slot6c(em, a):
        for k in range(3):
            em.wf32(a[0] + 4 * k, vals[(len(em.calllog) + k) % 32])
        return 0

    def slot40(em, a):
        em.w32(a[0], handles[len(em.calllog) % 4])
        return 0

    self_ = rnd(c, 0x100)
    e.w32(self_, vtable(c, 'col', 0x40, impl={0x40: slot40, 0x48: slot48, 0x50: slot50, 0x6c: slot6c},
                        argwords={0x40: 1, 0x48: 1, 0x50: 1, 0x6c: 1}))
    msg = e.alloc(0xb00)
    e.w32(msg, vtable(c, 'msg58', 0x80, impl={0x58: lambda em, a: m_obj}, argwords={0x58: 1}))
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    out = e.alloc(4 + 48 * 4)
    e.wbytes(out, bytes(4 + 48 * 4))
    return [self_, out]


S(0x58a8d0, 'unnamed 0x58a8d0', 'fastcall', None, ret='eax', gen=_col, n=300)
