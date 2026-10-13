"""specs_s1211.py - fresh slice 12, batch 11 (3 functions). _stricmp (IAT 0x676414) is replaced by a logging Python
stub with the CRT's ASCII case-folding; 0x565360 is hooked."""
from pilot import S
from engine_stubs import zero_obj, set_global
from helpers12 import rand_obj, hk, done


def _cstr(em, p):
    b = bytearray()
    while True:
        ch = em.rbytes(p + len(b), 1)[0]
        if not ch:
            return bytes(b)
        b.append(ch)


def _g4321c0(c):
    def h(em, r):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = _cstr(em, a).lower(), _cstr(em, b).lower()
        em.calllog.append(('_stricmp', 0, 0, (a, b)))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    c.emu.w32(0x676414, c.emu.stub_fn('_stricmp', h))
    words = [b'tank', b'Heli', b'SOLDIER', b'door', b'x', b'gun']

    def mk(w):
        p = c.emu.alloc(len(w) + 1, 1)
        c.emu.wbytes(p, w + b'\0')
        return p
    ng = c.rng.choice([0, 1, 2, 3])
    tbl = zero_obj(c, 16 * (ng + 1))
    for g in range(ng):
        k = c.rng.choice([0, 1, 2, 3])
        ent = zero_obj(c, 12 * (k + 1))
        for i in range(k):
            c.emu.w32(ent + 12 * i, mk(c.rng.choice(words)))
        c.emu.w32(tbl + 16 * g, c.rng.getrandbits(16))
        c.emu.w32(tbl + 16 * g + 8, ent if (k or c.rng.random() < 0.5) else ent)
    eng = zero_obj(c, 0x1a00)
    c.emu.w32(eng + 0x190b, tbl)
    set_global(c, 0x70039c, eng)
    key = mk(c.rng.choice(words + [b'TANK', b'heli', b'none']))
    return done(c, [rand_obj(c, 0x10), key])


S(0x4321c0, 'FUN_004321c0 string table lookup (_stricmp)', 'thiscall', None, ret='eax', gen=_g4321c0)


def _g4ca240(c):
    o = rand_obj(c, 0xc0)
    a = rand_obj(c, 0x10)
    c.emu.w32(a + 8, rand_obj(c, 0x30))
    c.emu.w32(o + 0x44, a)
    return done(c, [o])


S(0x4ca240, 'FUN_004ca240 reset state block', 'thiscall', None, ret=None, gen=_g4ca240)


def _g565100(c):
    c.emu.hook(0x565360, hk(0x565360, 'f565360', 1, lambda em: em.arg32(0) ^ 0x3600))
    o = rand_obj(c, 0xcb0)
    idx = c.rng.choice([0, 1, 0x14, 0x15, 0x16, 0x17, c.rng.randrange(0, 0x40)])
    c.emu.w8(o + 0x1b5 + idx * 0x2a, c.rng.choice([0, 0, 1]))
    return done(c, [o, idx])


S(0x565100, 'FUN_00565100 select entry', 'thiscall', None, ret='eax', gen=_g565100)
