"""specs_s38080.py - cascade s8 batch 38080. cdecl(ctx, a, b, c) -> pointer. ctx = 0x200-byte random block: pool fields [0x1b0] limit / [0x1b4] cursor / [0x1b8] start marker (cursor sometimes == limit -> grow path),
[0xe8] namespace flag. Hooks: 0x6206e0 (grow: logs, extends the limit by 0x100 bytes of the same buffer, fails 8%), 0x620180 (logs; appends a flag byte plus a name chosen from xmlns forms, prefixed names and plain
names at the cursor, sets the start marker pool[0x10] (0 for 8%), fails 8%), 0x61fd60 (logs table, key text and size; returns a fresh entry whose first dword is the key (new) or another value (existing), null 5%)."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks

NAMES = [b'xmlns', b'xmlns:foo', b'xmlns:', b'xmlnsx', b'xmlnsx:y', b'a:b', b':x', b'abc', b'', b'pre:local', b'x:', b'xml:lang', b'xmln:q', b'p:q:r', b'longprefix:name', b'abcdefgh:z', b'abcdefghijkl']


def _cstr(em, p, lim=0x80):
    out = b''
    while len(out) < lim:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g61f5a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ctx = rnd(c, 0x200)
    buf = e.alloc(0x800, 1)
    e.wbytes(buf, bytes(0x800))
    cur = buf + r.choice([0, 0x10, 0x20])
    limit = cur if r.random() < 0.15 else (cur + r.choice([2, 3, 5, 8]) if r.random() < 0.25 else buf + 0x400)
    e.w32(ctx + 0x1b0, limit)
    e.w32(ctx + 0x1b4, cur)
    e.w32(ctx + 0x1b8, buf + r.randrange(0, 8))
    e.w32(ctx + 0xe8, r.choice([0, 1, 1, 1]))
    pool = ctx + 0x1a8

    def grow(em, res_):
        p = em.arg32(0)
        em.calllog.append(('grow', p))
        ok = r.random() > 0.08
        if ok:
            em.w32(p + 8, em.r32(p + 0xc) + 0x100)
        em.ret(eax=1 if ok else 0, argbytes=0)
    e.hook(0x6206e0, grow)

    def rdname(em, res_):
        p, a, b, cc = (em.arg32(i) for i in range(4))
        ok = r.random() > 0.08
        nm = r.choice(NAMES)
        fl = r.getrandbits(8) | 1
        em.calllog.append(('rdname', p, a, b, cc, ok, nm, fl))
        if ok:
            cur_ = em.r32(p + 0xc)
            em.wbytes(cur_, bytes([fl]) + nm)
            em.w32(p + 0x10, cur_ if r.random() > 0.08 else 0)
            em.w32(p + 0xc, cur_ + 1 + len(nm))
        em.ret(eax=1 if ok else 0, argbytes=0)
    e.hook(0x620180, rdname)

    def find(em, res_):
        t, k, sz = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('find', t, k, sz, _cstr(em, k)))
        ent = rnd(c, 0x20)
        v = r.random()
        if v < 0.05:
            ent = 0
        elif v < 0.6:
            em.w32(ent, k)
        em.ret(eax=ent, argbytes=0)
    e.hook(0x61fd60, find)
    return [ctx, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x61f5a0, 'GUESS intern xml name', 'cdecl', None, ret='eax', gen=_g61f5a0, note='batch38080')
