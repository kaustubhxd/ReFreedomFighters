"""specs_s5790.py - unclaimed-57, batch 90: 0x5d8340 (GUESS name unnamed_5d8340). Thiscall, one stack argument db (ret 4), no return value.
Hooked: 0x4e5ea0 (string reader: returns a per-case heap string with NUL at a length L; L is above 0x63 in about one case in seven, which
runs the assert hook), 0x4e5e60 (dword reader, two calls in order, each XORed with the dword at db), 0x7003b0 (assert hook: a logging stub,
so the original's int3 branch is not exercised), the CRT strncpy import at 0x67642c (stub_import: copies up to n bytes, stops at NUL,
zero-pads), and the engine sub-object's slot +0x58 (one argument, logged). db's first dword points at a byte buffer whose first byte is
0xff in about one case in five (the byte test then fails). The strncpy destination is this+0x4e, so the 0x63 bytes are checked by the heap."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d8340(c):
    e = c.emu
    # the boundary length 0x63 is generated in about one case in ten, so the strict test against 0x63 is checked at its edge
    r_len = c.rng.random()
    L = 0x63 if r_len < 0.1 else (c.rng.randrange(0x64, 0x71) if r_len < 0.25 else c.rng.randrange(0, 0x63))
    sbuf = _rnd(c, 0x80)
    text = bytes(c.rng.choice(b'abcdefghijklmnopqrstuvwxyz0123456789_') for _ in range(L)) + b'\x00'
    e.wbytes(sbuf, text)
    dv = [c.rng.getrandbits(32), c.rng.getrandbits(32)]
    di = [0]
    rv58 = c.rng.getrandbits(32)
    b0 = 0xff if c.rng.random() < 0.2 else c.rng.getrandbits(8)
    bbuf = _rnd(c, 0x10)
    e.wbytes(bbuf, bytes([b0]))

    def h5ea0(em, r):
        em.ret(eax=sbuf, argbytes=0)
    e.hook(0x4e5ea0, h5ea0)

    def h5e60(em, r):
        v = dv[di[0] % 2]
        di[0] += 1
        em.ret(eax=v ^ em.r32(em.reg('ecx')), argbytes=0)
    e.hook(0x4e5e60, h5e60)

    def assert_fn(em, r):
        em.calllog.append(('assert', 0, None, ()))
        em.ret(eax=0)
    e.w32(0x7003b0, e.stub_fn('assert', assert_fn))

    def strncpy(em, rr):
        dst, src, cnt = em.arg32(0), em.arg32(1), em.arg32(2)
        data = bytearray(em.rbytes(src, cnt))
        out = bytearray(cnt)
        for i in range(cnt):
            if data[i] == 0:
                break
            out[i] = data[i]
        em.wbytes(dst, bytes(out))
        em.ret(eax=dst, argbytes=0)
    e.stub_import('strncpy', strncpy)

    def h58(em, rr):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=rv58, argbytes=4)

    vt_sub = e.fake_vtable('d8340_sub', 160, {0x58: h58})
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0x40)
    e.w32(db, bbuf)
    self_obj = _rnd(c, 0x200)
    return [self_obj, db]


S(0x5d8340, 'unnamed_5d8340 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d8340,
  note='unclaimed-57 batch 90; readers 0x4e5ea0 and 0x4e5e60 hooked; assert 0x7003b0 logs; strncpy import stubbed; sub slot +0x58 fake')
