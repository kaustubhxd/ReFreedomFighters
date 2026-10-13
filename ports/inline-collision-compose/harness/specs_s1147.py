"""specs_s1147.py - collision thread batch 1147 (name GUESS): 0x4407c0. The CRT imports are stubbed at their IAT slots (as area 76
did for 0x602ff0): strchr (IAT 0x676254) and _memicmp (IAT 0x67640c) are Python implementations that read the guest strings, so
they are real behaviour, not recorders. The entries form a forward chain; each entry's type T carries a mask field, a name
pointer (or zero: the default string), and a slot-0x25c object. The string s holds a backslash in half of the cases."""
import struct
from pilot import S, F


def _find(c):
    e, r = c.emu, c.rng

    def strchr(em, rr):
        s, ch = em.arg32(0), em.arg32(1) & 0xff
        a = s
        for _ in range(4096):
            b = em.r8(a)
            if b == ch:
                em.ret(eax=a, argbytes=0)
                return
            if b == 0:
                break
            a += 1
        em.ret(eax=0, argbytes=0)
    def memicmp(em, rr):
        a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
        for k in range(n):
            x = em.r8(a + k)
            y = em.r8(b + k)
            if 65 <= x <= 90: x += 32
            if 65 <= y <= 90: y += 32
            if x != y:
                em.ret(eax=(1 if x > y else 0xffffffff), argbytes=0)
                return
        em.ret(eax=0, argbytes=0)
    e.w32(0x676254, e.stub_fn('strchr_iat', strchr))
    e.w32(0x67640c, e.stub_fn('memicmp_iat', memicmp))

    # the string s: a short name, a backslash in half the cases
    k = r.random()
    if k < 0.2:
        word = b'<noname>'                                  # matches the default name (T+4 zero)
    elif k < 0.25:
        word = b''                                         # an empty component
    else:
        word = bytes(r.choice(b'abcXYZ') for _ in range(r.randrange(1, 5)))
    text = word + (b'\\rest' if r.random() < 0.5 else b'') + b'\x00'
    s = e.alloc(len(text) + 16, 4)
    e.wbytes(s, text)
    # the default name string 0x67c8e8 is in the image; the entries use it or a copied name
    names = [e.alloc(16, 4) for _ in range(2)]
    e.wbytes(names[0], word.swapcase() + b'\x00')
    e.wbytes(names[1], bytes(r.choice(b'abcXYZ') for _ in range(r.randrange(1, 5))) + b'\x00')

    def slot25c(em, rr):
        em.calllog.append(('25c', em.arg32(0), em.arg32(1)))
        em.ret(eax=retv, argbytes=8)
    retv = r.getrandbits(32)
    vt = e.fake_vtable('T_4407c0', 0x100, {0x25c: slot25c})

    chain = []
    for k in range(r.randrange(0, 4)):
        T = e.alloc(0x40, 16)
        e.wbytes(T, bytes(r.getrandbits(8) for _ in range(0x40)))
        e.w32(T, vt)
        e.w32(T + 4, r.choice([0, names[0], names[1]]))
        e.w32(T + 0x30, r.choice([0x1, 0x2, 0x3, 0x4]))
        X = e.alloc(0x40, 16)
        e.wbytes(X, bytes(r.getrandbits(8) for _ in range(0x40)))
        fl = r.getrandbits(32)
        fl = (fl | 0x100000) if r.random() < 0.7 else (fl & ~0x100000)
        e.w32(X + 0x23, fl)
        e.w32(T + 0xc, X)
        ent = e.alloc(0x80, 16)
        e.wbytes(ent, bytes(r.getrandbits(8) for _ in range(0x80)))
        e.w32(ent + 0x54, T)
        chain.append(ent)
    for i in range(len(chain) - 1):
        e.w32(chain[i] + 0x60, chain[i + 1])
    if chain:
        e.w32(chain[-1] + 0x60, 0)
    self_ = e.alloc(0x80, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x80)))
    e.w32(self_ + 0x50, chain[0] if chain else 0)
    mask = r.choice([0x1, 0x2, 0x4, 0x8])
    return [self_, s, mask]


S(0x4407c0, 'entry walk: strchr and _memicmp (IAT stubs), the type mask, the name compare, slot 0x25c (name GUESS)', 'thiscall',
  None, ret='eax', gen=_find, note='batch1147')
