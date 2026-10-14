"""specs_s38002.py - cascade s8 batch 38002: 0x550db0 (name dispatch). _stricmp (IAT 0x676414) is a logging Python stub with the CRT's ASCII case folding; the ten handlers
are recording hooks returning random values; the assert hook 0x7003b0 is always set. Names: one of the 11 table strings from the exe image (random case) or an unknown one."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

STRS = [0x6a4b74, 0x6a4b80, 0x6a4b8c, 0x6a4b68, 0x69f3ac, 0x69f484, 0x6a4bbc, 0x6a4bc4, 0x6a4bcc, 0x69f26c, 0x6a4bd4]
HANDLERS = [0x55ed00, 0x55fad0, 0x560440, 0x5579b0, 0x51ae60, 0x51b6d0, 0x51f320, 0x522dc0, 0x520010, 0x51a8a0]


def _cstr(em, p):
    out = b''
    while len(out) < 80:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g550c50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def h(em, res_):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = _cstr(em, a).lower(), _cstr(em, b).lower()
        em.calllog.append(('_stricmp', 0, 0, (a, b)))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', h))
    for a in HANDLERS:
        hook_rec(c, a, 0, this=True, ret=lambda em, k: r.getrandbits(32), side=lambda em, k: em.calllog.append(('edx', em.reg('edx'))))
    if r.random() < 0.85:
        s = _cstr(e, r.choice(STRS))
        s = bytes(ch ^ 0x20 if (65 <= (ch | 0x20) <= 90 and r.random() < 0.5) else ch for ch in s)
    else:
        s = r.choice([b'nothing', b'', b'zzz'])
    p = e.alloc(len(s) + 1, 1)
    e.wbytes(p, s + b'\0')
    return [p, r.getrandbits(32), r.getrandbits(32)]


S(0x550db0, 'GUESS dispatch by name to fastcall handler', 'stdcall', None, ret='eax', gen=_g550c50, note='batch38002')
