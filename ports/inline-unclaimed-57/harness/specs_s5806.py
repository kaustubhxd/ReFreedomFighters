"""specs_s5806.py - unclaimed-57, batch 106: 0x5d81b0 (GUESS name unnamed_5d81b0). Thiscall, two stack arguments (a16, b; ret 8), returns 0. The word
a16 is this+0x4a in about four cases in ten, this+0x4c in about three in ten, otherwise random. The engine (global 0x70039c, a 0x2000-byte block)
has its own vtable: slot +0x1cc (one arg, logged) and +0xc (four args, logged); its float at +0x1b40 is written by the original. Its sub-object at
+0x9b has slots +0xac (returns a count 0 to 3), +0xa4 (no args, logged) and +0xa0 (one arg, logged); its pointer at +0x190f is an object with slot
+0xbc (no args, logged). The object at this+0x44 has slot +0x114 (one arg, logged). Callee 0x5d8470 (another area's function) is a logging stub with
ECX; it writes nothing and this+0xbc is set to zero or not at random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d81b0(c):
    e_ = c.emu
    count = c.rng.randrange(0, 4)

    def hA(name):
        def h(em, r):
            em.calllog.append((name, 0, None, tuple(em.arg32(k) for k in range(1))))
            em.ret(eax=0, argbytes=4)
        return h

    def h4args(em, r):
        em.calllog.append(('c', 0, None, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=0, argbytes=16)

    def h1cc(em, r):
        em.calllog.append(('1cc', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def hac(em, r):
        em.calllog.append(('ac', 0, None, ()))
        em.ret(eax=count, argbytes=0)

    def ha4(em, r):
        em.calllog.append(('a4', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    def ha0(em, r):
        em.calllog.append(('a0', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def hbc(em, r):
        em.calllog.append(('bc', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    def h114(em, r):
        em.calllog.append(('114', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h5d8470(em, r):
        em.calllog.append(('5d8470', 0, 'S' if em.reg('ecx') == self_obj else 'other', ()))
        em.ret(eax=0, argbytes=0)
    e_.hook(0x5d8470, h5d8470)

    vt_eng = e_.fake_vtable('d81b0_eng', 200, {0x1cc: h1cc, 0xc: h4args})
    vt_sub = e_.fake_vtable('d81b0_sub', 200, {0xac: hac, 0xa4: ha4, 0xa0: ha0})
    vt_p = e_.fake_vtable('d81b0_p', 200, {0xbc: hbc})
    vt_obj = e_.fake_vtable('d81b0_obj', 200, {0x114: h114})
    eng = _rnd(c, 0x2000)
    e_.w32(eng, vt_eng)
    sub = _rnd(c, 0x40)
    e_.w32(sub, vt_sub)
    e_.w32(eng + 0x9b, sub)
    p = _rnd(c, 0x40)
    e_.w32(p, vt_p)
    e_.w32(eng + 0x190f, p)
    e_.w32(0x70039c, eng)
    obj = _rnd(c, 0x40)
    e_.w32(obj, vt_obj)
    self_obj = _rnd(c, 0x200)
    e_.w32(self_obj + 0x44, obj)
    w4a = c.rng.getrandbits(16)
    w4c = c.rng.getrandbits(16)
    e_.wbytes(self_obj + 0x4a, bytes([w4a & 0xff, w4a >> 8]))
    e_.wbytes(self_obj + 0x4c, bytes([w4c & 0xff, w4c >> 8]))
    e_.w32(self_obj + 0xbc, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    x = c.rng.random()
    if x < 0.4:
        low = w4a
    elif x < 0.7:
        low = w4c
    else:
        low = c.rng.getrandbits(16)
    a16 = (c.rng.getrandbits(16) << 16) | low
    b = c.rng.getrandbits(32)
    return [self_obj, a16, b]


S(0x5d81b0, 'unnamed_5d81b0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_d81b0,
  note='unclaimed-57 batch 106; engine vtable slots +0x1cc and +0xc, sub slots +0xac, +0xa4, +0xa0, p slot +0xbc, obj slot +0x114 fake; 0x5d8470 hooked (logs)')
