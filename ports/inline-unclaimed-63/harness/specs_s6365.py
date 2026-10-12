"""specs_s6365.py - unclaimed-63 batch 65: 0x478e20 (ZActor::GetMoveTypeId; stdcall-like, one stack argument s, ret 4).
The table at 0x68ac68 (18 entries of name pointer and id) is read from the image as is. The argument is an image name in two thirds of
the cases (a hit), else a heap string (a miss, which logs). Fakes per case: 0x676414 (cdecl strcmp-like) is a stub that compares the two
strings it is given and returns -1, 0 or 1; the logger 0x700390 slot +0x20 returns a log object whose slot +0x2c (cdecl) records its
arguments."""
from pilot import S


def _gen_8e20(c):
    e = c.emu
    import struct
    names = [struct.unpack('<I', bytes(e.rbytes(0x68ac68 + 8 * i, 4)))[0] for i in range(0x12)]

    def cstr(addr):
        out = bytearray()
        for k in range(256):
            b = bytes(e.rbytes(addr + k, 1))
            if b == b'\x00':
                break
            out += b
        return bytes(out)

    def strcmp(em, a):
        x, y = cstr(em.arg32(0)), cstr(em.arg32(1))
        r = (x > y) - (x < y)
        em.calllog.append(('strcmp', None, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=r & 0xffffffff, argbytes=0)
    e.w32(0x676414, e.stub_fn('strcmp 0x676414', strcmp))

    def printf(em, a):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(3))))
        em.ret(eax=0, argbytes=0)
    logobj = e.alloc(0x40, 4)
    e.w32(logobj, e.fake_vtable('log', 0x100 // 4, {0x2c: printf}))
    lg = e.alloc(0x40, 4)
    e.w32(lg, e.logging_vtable('logger', 0x40 // 4, impl={0x20: lambda em, x: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    if c.rng.random() < 2 / 3:
        s = names[c.rng.randrange(0, 0x12)]
    else:
        raw = bytes(c.rng.choice(b'zyxw') for _ in range(c.rng.randint(1, 6))) + b'\x00'
        s = e.alloc(len(raw) + 4, 4)
        e.wbytes(s, raw)
    e.mu.ctl_flush_tb()
    return [s]


S(0x478e20, 'ZActor::GetMoveTypeId stdcall', 'stdcall', None, ret='eax', gen=_gen_8e20,
  note='unclaimed-63 batch 65; strcmp import stubbed; table read from the image')
