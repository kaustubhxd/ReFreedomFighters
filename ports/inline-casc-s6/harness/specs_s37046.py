"""specs_s37046.py - cascade s6 batch 37046: 0x43b820 (keyword parser). _stricmp (IAT 0x676414) is a logging stub with ASCII case folding; names are the nine keyword strings read
from the exe image (random case) or unknown words; logger at 0x700390 (slot 0x20 -> line object with cdecl slot 0x2c)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

KEYS = [0x67a0a8, 0x67a0e0, 0x67a0ac, 0x67c0e4, 0x67a0a0, 0x67a0c8, 0x67a0d4, 0x67a0b4, 0x677b5c]


def _cstr(em, p):
    out = b''
    while len(out) < 80:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g43b820(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def stricmp(em, r_):
        sa, sb = _cstr(em, em.arg32(0)), _cstr(em, em.arg32(1))
        em.calllog.append(('_stricmp', sa, sb))
        a, b = sa.lower(), sb.lower()
        em.ret(eax=0 if a == b else (1 if a > b else 0xffffffff), argbytes=0)
    e.stub_import('_stricmp', stricmp)

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(1), bytes(_cstr(em, em.arg32(2)))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    if r.random() < 0.85:
        s = _cstr(e, r.choice(KEYS))
        s = bytes(ch ^ 0x20 if (65 <= (ch | 0x20) <= 90 and r.random() < 0.5) else ch for ch in s)
    else:
        s = r.choice([b'nothing', b'', b'zzz', b'Idle2'])
    p = e.alloc(len(s) + 8, 1)
    e.wbytes(p, s + b'\0')
    me = rnd(c, 0xc0)
    return [me, p]


S(0x43b820, 'GUESS parse keyword', 'thiscall', None, ret=None, gen=_g43b820, note='batch37046')
