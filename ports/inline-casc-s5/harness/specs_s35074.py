"""specs_s35074.py - 0x4d40f0 (cdecl(this, fmt, va0, va1, va2), ret=None; extra words are the variable arguments). this: 0x1000 random bytes; unaligned ring index at +0xfaf (0..0x3e7, 0x3e7 often so the wrap happens) and the entry
pointer at [this + 4 * idx + 0xf] (unaligned) -> 0xa0-byte block; fmt: short random text (a quarter of the cases 0x3ff, 0x400, 0x401 or 0x410 characters); 0x42abee hooked (cdecl, 3 args; the first two variable-argument dwords
logged; writes a fixed text with or without ')' into the buffer); strchr and strncpy imports stubbed in Python (logging, with real semantics for the copy)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4d40f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    txt = bytes(r.choice(b'abc XYZ09') for _ in range(r.randint(0, 40)))
    if r.random() < 0.7:
        k = r.randint(0, len(txt))
        txt = txt[:k] + b')' + txt[k:]
    if r.random() < 0.15:
        txt = bytes(r.choice(b'abc') for _ in range(0x90 + r.randint(0, 20))) + txt
    txt += b'\0'

    def h(em, rr):
        em.calllog.append(('42abee', em.arg32(1), em.r32(em.arg32(2)), em.r32(em.arg32(2) + 4)))
        em.wbytes(em.arg32(0), txt)
        em.ret(eax=0)
    e.hook(0x42abee, h)

    def rdstr(em, p, n=0x400):
        s = b''
        while len(s) < n:
            ch = bytes(em.rbytes(p + len(s), 1))
            if ch == b'\0':
                break
            s += ch
        return s

    def schr(em, rr):
        p, ch = em.arg32(0), em.arg32(1)
        s = rdstr(em, p)
        em.calllog.append(('strchr', s, ch))
        i = s.find(bytes([ch & 0xff]))
        em.ret(eax=0 if i < 0 else p + i)

    def sncpy(em, rr):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        src = rdstr(em, s)
        em.calllog.append(('strncpy', d, src, n))
        out = src[:n] + bytes(max(0, n - len(src)))
        em.wbytes(d, out[:n])
        em.ret(eax=d)
    e.stub_import('strchr', schr)
    e.stub_import('strncpy', sncpy)
    idx = r.choice([0x3e7, 0x3e7, 0, 1, r.randint(0, 0x3e7)])
    me = rnd(c, 0x1000)
    e.wbytes(me + 0xfaf, idx.to_bytes(4, 'little'))
    e.wbytes(me + 4 * idx + 0xf, rnd(c, 0xa0).to_bytes(4, 'little'))
    fmt = rnd(c, 0x440)
    if r.random() < 0.25:
        L = r.choice([0x3ff, 0x400, 0x401, 0x410])
        e.wbytes(fmt, bytes(r.choice(b'abc%d') for _ in range(L)) + b'\0')
    else:
        e.wbytes(fmt, bytes(r.choice(b'abc%d') for _ in range(r.randint(0, 30))) + b'\0')
    return [me, fmt, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4d40f0, 'GUESS printf into ring buffer keeping text after paren', 'cdecl', None, ret=None, gen=_g4d40f0, note='batch35074')
