"""specs_s1219.py - fresh slice 12, batch 19."""
from pilot import S
from helpers12 import rand_obj, hk, done


def _cstr(em, a):
    out = b''
    while True:
        ch = bytes(em.mu.mem_read(a + len(out), 1))
        if ch == b'\0':
            return out
        out += ch


def g_4cc400(c):
    def h(em, r):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = _cstr(em, a).lower(), _cstr(em, b).lower()
        em.calllog.append(('_stricmp', 0, 0, (a, b)))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    c.emu.w32(0x676414, c.emu.stub_fn('_stricmp', h))
    words = [b'Tank', b'tank', b'TANKS', b'tan', b'', b'heli', b'Heli2', b'a[b', b'A_b', b'\xe9t\xe9', b'zz', b'Z']

    def mk(w):
        p = c.emu.alloc(len(w) + 1, 1)
        c.emu.wbytes(p, w + b'\0')
        return p
    if c.rng.random() < 0.3:
        wa = bytes(c.rng.getrandbits(8) | 1 for _ in range(c.rng.randrange(0, 6)))
        wb = bytes(c.rng.getrandbits(8) | 1 for _ in range(c.rng.randrange(0, 6)))
    else:
        wa, wb = c.rng.choice(words), c.rng.choice(words)
    return done(c, [mk(wa), mk(wb)])


def g_428440(c):
    c.emu.hook(0x435a10, hk(0x435a10, 'base', 0))
    c.emu.hook(0x4361a0, hk(0x4361a0, 'name', 1))
    c.emu.hook(0x436170, hk(0x436170, 'set', 1))
    c.emu.w32(0x6f5630, c.rng.getrandbits(32))
    return done(c, [rand_obj(c, 0xc0)] + [c.rng.getrandbits(32) for _ in range(4)])


S(0x4cc400, 'FUN_004cc400 name order test (case-insensitive)', 'fastcall', None, ret='al', gen=g_4cc400)
S(0x428440, 'FUN_00428440 constructor (vt 0x678df4, 16-byte value), SEH', 'thiscall', None, ret='eax', gen=g_428440)
