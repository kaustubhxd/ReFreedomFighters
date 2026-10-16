"""specs_s5817.py - unclaimed-57, batch 117: 0x5d76f0 (GUESS name unnamed_5d76f0). Thiscall, no stack args, plain ret. Hooked callees: 0x5d7e00 (batch 107) and
0x5d7bc0 (area 49), both logging stubs that write nothing. The engine (global 0x70039c) has an object q at +0x1907 (slot +0x38, two args, logged; returns a
flag from a per-case pair), and a sub-object at +0x9b (slot +0x4c, one arg, logged; returns a per-case dword). this+0x14e is an object r14 (slot +0x30, one
arg, logged, returns a dword; slot +0x14, no args, returns a dword). this+0x44 is an object obj (slots +0x128, +0x12c, +0x130, three args, logged). The
flags at +0x1cc, +0x1c3 and +0x1e6 are random bits; +0x156 is 0, 1 or 2; the counter +0x13c is 0 to 2 and the limit +0x48 is 1 to 3; the table at +0x4c has
three 12-byte entries of random values. The word fields +0x142 and +0x14a and the dword at +0x1d1 are random. The engine dword at +0x40 is random."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d76f0(c):
    e = c.emu
    fl = [c.rng.choice([0, 1]), c.rng.choice([0, 1])]
    fi = [0]
    rv14 = c.rng.getrandbits(32)
    r30 = c.rng.getrandbits(32)
    r4c = c.rng.getrandbits(32)

    def h5d7e00(em, r):
        em.calllog.append(('5d7e00', 0, 'S' if em.reg('ecx') == self_obj else 'other', ()))
        em.ret(eax=0, argbytes=0)
    e.hook(0x5d7e00, h5d7e00)

    def h5d7bc0(em, r):
        em.calllog.append(('5d7bc0', 0, 'S' if em.reg('ecx') == self_obj else 'other', ()))
        em.ret(eax=0, argbytes=0)
    e.hook(0x5d7bc0, h5d7bc0)

    def hq38(em, r):
        i = fi[0]
        fi[0] += 1
        em.calllog.append(('q38', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=fl[i % 2], argbytes=8)

    def hsub4c(em, r):
        em.calllog.append(('s4c', 0, None, (em.arg32(0),)))
        em.ret(eax=r4c, argbytes=4)

    def hr30(em, r):
        em.calllog.append(('r30', 0, None, (em.arg32(0),)))
        em.ret(eax=r30, argbytes=4)

    def hr14(em, r):
        em.calllog.append(('r14', 0, None, ()))
        em.ret(eax=rv14, argbytes=0)

    def hobj(name):
        def h(em, r):
            if name == '130':
                # the third argument points at a stack pair: log its contents, never its address
                em.calllog.append((name, 0, None, (em.arg32(0), em.arg32(1), em.rbytes(em.arg32(2), 8))))
            else:
                em.calllog.append((name, 0, None, tuple(em.arg32(k) for k in range(3))))
            em.ret(eax=0, argbytes=12)
        return h

    vt_q = e.fake_vtable('d76f0_q', 200, {0x38: hq38})
    vt_sub = e.fake_vtable('d76f0_sub', 200, {0x4c: hsub4c})
    vt_r = e.fake_vtable('d76f0_r', 200, {0x30: hr30, 0x14: hr14})
    vt_o = e.fake_vtable('d76f0_o', 200, {0x128: hobj('128'), 0x12c: hobj('12c'), 0x130: hobj('130')})
    q = _rnd(c, 0x40)
    e.w32(q, vt_q)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    r14 = _rnd(c, 0x40)
    e.w32(r14, vt_r)
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x1907, q)
    e.w32(eng + 0x9b, sub)
    eng40 = c.rng.randrange(-300, 301)
    e.w32(eng + 0x40, eng40 & 0xffffffff)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x300)
    e.wbytes(self_obj + 0x1cc, bytes([c.rng.choice([0, 1])]))
    e.wbytes(self_obj + 0x1c3, bytes([c.rng.choice([0, 1])]))
    e.wbytes(self_obj + 0x1e6, bytes([c.rng.choice([0, 1])]))
    e.w32(self_obj + 0x156, c.rng.choice([0, 1, 2]))
    e.w32(self_obj + 0x1c8, c.rng.randrange(-300, 301) & 0xffffffff)
    c1c4 = c.rng.randrange(-300, 301)
    e.w32(self_obj + 0x1c4, c1c4 & 0xffffffff)
    idx0 = c.rng.randrange(0, 3)
    e.w32(self_obj + 0x13c, idx0)
    e.w32(self_obj + 0x48, c.rng.randrange(1, 4))
    e.w32(self_obj + 0x14e, r14)
    e.w32(self_obj + 0x44, obj)
    e.wbytes(self_obj + 0x142, bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)]))
    e.wbytes(self_obj + 0x14a, bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)]))
    e.w32(self_obj + 0x1d1, c.rng.getrandbits(32))
    for i in range(3):
        for k in range(3):
            e.w32(self_obj + 0x4c + 12 * i + 4 * k, c.rng.randrange(-300, 301) & 0xffffffff)
    # the cut value is trunc((float)(engine+0x40 - this+0x1c4) * c1 * c2) with the exe's constants, rounded to float at each step;
    # in about two cases in five entry 0 of the current index equals it exactly (the strict > test is checked at its edge)
    if c.rng.random() < 0.4:
        def f32(x):
            return struct.unpack('<f', struct.pack('<f', x))[0]
        c1 = struct.unpack('<f', e.mu.mem_read(0x6785e4, 4))[0]
        c2 = struct.unpack('<f', e.mu.mem_read(0x685270, 4))[0]
        t = f32(float(eng40 - c1c4))
        cut = int(f32(f32(t * c1) * c2))
        e.w32(self_obj + 0x4c + 12 * idx0, cut & 0xffffffff)
    return [self_obj]


S(0x5d76f0, 'unnamed_5d76f0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d76f0,
  note='unclaimed-57 batch 117; 0x5d7e00 (batch 107) and 0x5d7bc0 (area 49) hooked; q, sub, r14, obj fake slots; flags random')
