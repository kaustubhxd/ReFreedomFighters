"""specs_s3012.py - unclaimed-30 batch 12 (docs/20-unclaimed-30.md, claim 1): ZFFActor::ReplaceSpecialAnim (0x5a2890). Names are
"cc_punch", "cc_kick", another string, or null; the reporter (pfspec) takes the error. The object's slots 0x5a0 (returns a value)
and 0x598 (takes the old value) are logged. Return value is not compared (ret None)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable, reporter


def _stricmp(em, rr):
    # _stricmp: ASCII case folding; only the zero / non-zero result is used by the exe
    def rd(a):
        out = bytearray()
        while True:
            b = em.r8(a)
            if b == 0:
                return bytes(out)
            out.append(b)
            a += 1
    def low(b):
        return b + 32 if 65 <= b <= 90 else b
    x, y = rd(em.arg32(0)), rd(em.arg32(1))
    eq = len(x) == len(y) and all(low(p) == low(q) for p, q in zip(x, y))
    em.ret(eax=0 if eq else 1, argbytes=0)


def _rsa(c):
    e = c.emu
    r = c.rng
    reporter(c, 0.0)
    e.stub_import('_stricmp', _stricmp)
    kind = r.choice(['punch', 'kick', 'other', 'null'])
    if kind == 'null':
        name = 0
    elif kind == 'punch':
        name = 0x6ae918
    elif kind == 'kick':
        name = 0x6ae924
    else:
        name = e.alloc(16)
        e.wbytes(name, r.choice([b'cc_other\x00', b'CC_PUNCH\x00', b'Cc_Kick\x00']))
    vals = [r.getrandbits(32) for _ in range(8)]
    obj = rnd(c, 0x900)
    e.w32(obj, vtable(c, 'zffactor', 0x300, impl={0x5a0: lambda em, a: vals[len(em.calllog) % 8]},
                      argwords={0x5a0: 1, 0x598: 1}))
    idv = 0 if r.random() < 0.2 else r.getrandbits(32) | 1
    return [obj, name, idv]


S(0x5a2890, 'ZFFActor::ReplaceSpecialAnim', 'thiscall', None, gen=_rsa, n=300)
