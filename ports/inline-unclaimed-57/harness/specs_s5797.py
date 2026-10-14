"""specs_s5797.py - unclaimed-57, batch 97: 0x5d7610 (GUESS name unnamed_5d7610). Thiscall, one stack argument db (ret 4), no return. The same
shape as batch 90 (0x5d8340): hooked string reader 0x4e5ea0 (a heap string, longer than 0x63 in about one case in seven, which runs the
assert hook 0x7003b0, a logging stub), the CRT strncpy import at 0x67642c (stub_import, zero-padded), and the dword reader 0x4e5e60 (each call
returns a per-call value XORed with the dword at db). db's first dword points at a byte buffer whose first byte is 0xff in about one case in
five (the byte test then fails)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d7610(c):
    e = c.emu
    # the boundary length 0x63 is generated in about one case in ten, so the strict test against 0x63 is checked at its edge
    r_len = c.rng.random()
    L = 0x63 if r_len < 0.1 else (c.rng.randrange(0x64, 0x71) if r_len < 0.25 else c.rng.randrange(0, 0x63))
    sbuf = _rnd(c, 0x80)
    text = bytes(c.rng.choice(b'abcdefghijklmnopqrstuvwxyz0123456789_') for _ in range(L)) + b'\x00'
    e.wbytes(sbuf, text)
    dv = [c.rng.getrandbits(32) for _ in range(6)]
    di = [0]
    b0 = 0xff if c.rng.random() < 0.2 else c.rng.getrandbits(8)
    bbuf = _rnd(c, 0x10)
    e.wbytes(bbuf, bytes([b0]))

    def h5ea0(em, r):
        em.ret(eax=sbuf, argbytes=0)
    e.hook(0x4e5ea0, h5ea0)

    def h5e60(em, r):
        v = dv[di[0] % 6]
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

    db = _rnd(c, 0x40)
    e.w32(db, bbuf)
    self_obj = _rnd(c, 0x200)
    return [self_obj, db]


S(0x5d7610, 'unnamed_5d7610 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d7610,
  note='unclaimed-57 batch 97; readers 0x4e5ea0 and 0x4e5e60 hooked; assert 0x7003b0 logs; strncpy import stubbed')
