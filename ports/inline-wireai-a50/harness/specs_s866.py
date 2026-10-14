"""specs_s866.py - area 50, batch 866: 0x42b390 (name GUESS), thiscall, two stack args (ret 8); the port is void.
Stood in: the block allocator 0x6014a0 (a fresh block of the requested size, logged). The memmove import (0x676278) is a stub
that copies and logs (dst, src, n). The C string is generated (length 0..12). The exe's SEH frame is not reproduced."""
from pilot import S
from anim_common import only_hooks, rnd, install_memset


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})

    def alloc(e, rr):
        n = e.arg32(0)
        e.calllog.append(('alloc6014a0', n))
        e.ret(eax=e.alloc(n, 8), argbytes=4)

    def mv(e, rr):
        d, s, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memmove', d, s, n))
        if n:
            e.wbytes(d, e.rbytes(s, n))
        e.ret(eax=d, argbytes=0)

    only_hooks(c, {0x6014a0: alloc})
    e.stub_import('memmove', mv)
    install_memset(c)
    self = rnd(c, 0x40)
    L = r.randint(0, 12)
    txt = bytes(r.choice(b'abcdefgh') for _ in range(L)) + b'\x00'
    s = rnd(c, 32)
    e.wbytes(s, txt)
    return [self, s, 0]


S(0x42b390, 'Fn42b390 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch866')
