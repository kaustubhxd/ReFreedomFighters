"""specs_s37038.py - cascade s6 batch 37038: 0x4e5160 (name lookup). _stricmp (IAT 0x676414) is a logging Python stub; the wildcard matcher 0x4cc850 runs as original code on
spec strings. this+4 -> header whose +4 flags select the entry list; this+0xc = string pool; entry lists have {count, flags, offset-of-table, ...}."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _cstr(em, p):
    out = b''
    while len(out) < 200:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g4e5160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def fold(b):
        return bytes(x + 32 if 65 <= x <= 90 else x for x in b)

    def cmp(a, b):
        a, b = fold(a), fold(b)
        return 0 if a == b else (0xffffffff if a < b else 1)

    def strchr(em, r_):
        p = em.arg32(0)
        ch = em.arg32(1) & 0xff
        sb = _cstr(em, p) + b'\0'
        i = sb.find(bytes([ch]))
        em.ret(eax=p + i if i >= 0 else 0, argbytes=0)

    def memicmp(em, r_):
        a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.ret(eax=cmp(em.rbytes(a, n), em.rbytes(b, n)) if n else 0, argbytes=0)

    def stricmp(em, r_):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = _cstr(em, a), _cstr(em, b)
        em.calllog.append(('_stricmp', sa, sb))
        em.ret(eax=cmp(sa, sb), argbytes=0)
    e.stub_import('strchr', strchr)
    e.stub_import('_memicmp', memicmp)
    e.stub_import('_stricmp', stricmp)
    words = [b'alpha', b'ALPHA', b'beta', b'be*', b'a*a', b'gamma', b'', b'*', b'abc', b'a?c', b'alp*']
    pool = bytearray(b'\0')
    offs = {}
    for w in words:
        offs[w] = len(pool)
        pool += w + b'\0'
    pbase = e.alloc(len(pool) + 0x100, 1)
    e.wbytes(pbase, bytes(pool))
    entries = [r.choice(words) for _ in range(r.choice([0, 1, 2, 3, 4]))]

    def mkstruct(tab_flag):
        # {count, flags, offsetOfTable, ..., table}
        n = len(entries)
        st = e.alloc(0x20 + 4 * n + 16, 4)
        e.w32(st, n)
        f = tab_flag
        e.w32(st + 4, f)
        off = r.choice([0x10, 0xc, 0x14])
        e.w32(st + 8, off)
        tabo = 8 if (f & 0xc0000000) not in (0x40000000, 0x80000000, 0xc0000000) else off
        for i, w in enumerate(entries):
            e.w32(st + tabo + 4 * i, offs[w])
        return st
    structflag = r.choice([0, 0x40000000, 0x80000000, 0xc0000000, 0x1234])
    hdr = e.alloc(0x40 + 4 * 8 + 0x80, 4)
    e.w32(hdr + 4, 0x80000000 | (0x40000000 if r.random() < 0.5 else 0) | r.getrandbits(8))
    use_indirect = e.r32(hdr + 4) & 0x40000000
    idxn = r.choice([0, 1, 2])
    e.w32(hdr + 0x10, idxn)
    st = mkstruct(structflag)
    # place the structure bytes at the location the function computes
    size = 0x20 + 4 * len(entries) + 16
    loc = (hdr + idxn * 4 + 0x14) if use_indirect else (hdr + 0x10)
    e.wbytes(loc, e.rbytes(st, size))
    me = rnd(c, 0x20)
    e.w32(me + 4, hdr)
    e.w32(me + 0xc, pbase)
    nm = r.choice(words + [b'ALPHA', b'be', b'al*pha*', b'ALP*HA', b'ga*mma', b'**ta'])
    if b'*' in nm:
        stripped = nm.replace(b'*', b'').lower()
        if stripped not in [w_.lower() for w_ in entries]:
            nm = r.choice([b'alpha', b'ALPHA', b'beta', b'be', b'abc', b'zzz'])
    p = e.alloc(len(nm) + 0x100, 1)
    e.wbytes(p, nm + b'\0')
    return [me, p]


S(0x4e5160, 'GUESS lookup name in table', 'thiscall', None, ret='eax', gen=_g4e5160, note='batch37038')
