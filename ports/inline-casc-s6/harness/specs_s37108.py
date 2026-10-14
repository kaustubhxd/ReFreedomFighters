"""specs_s37108.py - cascade s6 batch 37108: 0x500020 (name dispatch, stdcall(name, a, b) ret 0xc). _stricmp (IAT 0x676414) is a logging Python stub with ASCII case folding; the eight
handlers are hooks recording ecx / edx (fastcall) and returning random values; the assert hook is always set. Names: one of the eight table strings from the exe image (random
case) or an unknown one."""
from pilot import S
from recruits_util import clear_hooks

STRS = [0x69c770, 0x69c77c, 0x69c784, 0x69c790, 0x685230, 0x69c754, 0x69c75c, 0x69c768]
HANDLERS = [0x50b680, 0x50d8e0, 0x510f90, 0x511830, 0x504660, 0x506160, 0x5096c0, 0x50a540]


def _cstr(em, p):
    out = b''
    while len(out) < 80:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g500020(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def h(em, res_):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = _cstr(em, a).lower(), _cstr(em, b).lower()
        em.calllog.append(('_stricmp', (a, b)))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', h))
    for addr in HANDLERS:
        def mk(ad):
            def hh(em, res_):
                em.calllog.append(('h', ad, em.reg('ecx'), em.reg('edx')))
                em.ret(eax=r.getrandbits(32), argbytes=0)
            return hh
        e.hook(addr, mk(addr))
    if r.random() < 0.85:
        s = _cstr(e, r.choice(STRS))
        s = bytes(ch ^ 0x20 if (65 <= (ch | 0x20) <= 90 and r.random() < 0.5) else ch for ch in s)
    else:
        s = r.choice([b'nothing', b'', b'zzz'])
    p = e.alloc(len(s) + 1, 1)
    e.wbytes(p, s + b'\0')
    return [p, r.getrandbits(32), r.getrandbits(32)]


S(0x500020, 'GUESS dispatch by name to fastcall handler', 'stdcall', None, ret='eax', gen=_g500020, note='batch37108')
