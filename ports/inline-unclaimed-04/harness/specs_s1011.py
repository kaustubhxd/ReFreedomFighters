"""specs_s1011.py - unclaimed-04 batch 11 (docs/20-unclaimed-04.md): CImpactResponse::Init (0x5dc3f0, vtable).
thiscall with two stack arguments (ret 8); the first is unused, the second is a DBREAD reference (b).
The function calls 0x4e6330 (ecx = b, one stack argument: this+0x48, ret 4), then 0x4e5ea0 (ecx = b, returns a string
pointer), then _strdup of that string (IAT 0x676404), and stores the copy at this+0x4c.
The DBREAD helpers 0x4e6330 and 0x4e5ea0 are Python stubs here (GUESS: they read tagged records; their bodies are not
verified in this batch). The string the second helper returns is chosen per case; _strdup is a Python copy from the
harness heap that logs its argument."""
from pilot import S


def _cstr(e, p, n=256):
    return e.rbytes(p, n).split(b'\0')[0]


def _setup(c):
    e = c.emu

    def h6330(em, r):
        em.calllog.append(('4e6330', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h5ea0(em, r):
        em.calllog.append(('4e5ea0', 0, em.reg('ecx'), ()))
        em.ret(eax=getattr(em, 'impact_str', 0), argbytes=0)

    def strdup(em, r):
        s = _cstr(em, em.arg32(0))
        em.calllog.append(('_strdup', 0, 0, (s,)))
        p = em.alloc(len(s) + 1, 4)
        em.wbytes(p, s + b'\0')
        em.ret(eax=p, argbytes=0)

    e.hook(0x4e6330, h6330)
    e.hook(0x4e5ea0, h5ea0)
    e.stub_import('_strdup', strdup)


def _args(c):
    e = c.emu
    o = e.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    s = e.alloc(16, 4)
    text = c.rng.choice([b'', b'hit', b'ab12', b'Impact_Spark'])
    e.wbytes(s, text + b'\0')
    e.impact_str = s
    b = e.alloc(0x20, 4)
    e.wbytes(b, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    return [o, c.rng.getrandbits(32), b]


S(0x5dc3f0, 'CImpactResponse::Init (high) thiscall', 'thiscall', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 11; DBREAD helpers 0x4e6330 and 0x4e5ea0 are hooks (GUESS); _strdup is a Python copy')
