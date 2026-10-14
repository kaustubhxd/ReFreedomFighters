"""specs_s985.py - area 56 band, claim A51 (0x532ed0): bump-allocates a record; one register-argument call.

this is a 0x5400-byte object of random bytes. [this+0x51a9] points to a 0x1000-byte buffer of random bytes (the record is 0x44 bytes
and the advance is 0x44 plus the record's +4 dword, which the exe rewrites to 0x44 first). The fields this+0x6e, +0x72, +0x76 and this+0x4a
are random. 0x4de420 is hooked (GUESS: fastcall, two register arguments, plain ret, no effect). ret=None (void)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h(e2, r):
        e2.calllog.append(('H4de420', e2.reg('ecx'), e2.reg('edx')))
        e2.ret(argbytes=0)

    e.hook(0x4de420, h)
    this = e.alloc(0x5400, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x5400)))
    buf = e.alloc(0x1000, 4)
    e.wbytes(buf, bytes(rng.getrandbits(8) for _ in range(0x1000)))
    e.w32(this + 0x51a9, buf)
    return [this]


S(0x532ed0, 'unnamed 0x532ed0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A51; 0x4de420 hooked (GUESS, fastcall)')
