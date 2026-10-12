"""specs_s1008.py - unclaimed-04 batch 8 (docs/20-unclaimed-04.md): ZInputAction::AddNodes (0x4379f0, high name).
thiscall, two stack arguments (ret 8): s (char *, '+'-separated tokens, leading spaces skipped) and flag (bool, the
second argument of the per-token virtual call).
The exe copies s into a buffer from 0x41e290 (operator new, cdecl, one argument: length + 1), splits it on '+' and
spaces, calls virtual slot 0 of this once per token (thiscall with the token and flag), and frees the buffer through
0x634273 (cdecl, pointer and size 1). A first non-space '0' or an empty string does nothing but the free.
Stubs (GUESS: the allocator and the free are the usual CRT pair, unverified here): 0x41e290 returns a block from the
harness heap and logs its size; 0x634273 logs its arguments. The virtual slot 0 logs the token text and the flag."""
from pilot import S


def _cstr(e, p, n=256):
    return e.rbytes(p, n).split(b'\0')[0]


def _setup(c):
    e = c.emu

    def new41(em, r):
        size = em.arg32(0)
        em.calllog.append(('41e290', 0, 0, (size,)))
        p = em.alloc(size, 4)
        em.wbytes(p, bytes(size))
        em.ret(eax=p, argbytes=0)

    def free34(em, r):
        em.calllog.append(('634273', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    e.hook(0x41e290, new41)
    e.hook(0x634273, free34)


_ALPHA = b'ab+ 0+ +'


def _args(c):
    e = None
    n = c.rng.randrange(0, 12)
    body = bytes(c.rng.choice(_ALPHA) for _ in range(n))
    if c.rng.random() < 0.1:
        body = b'0' + body
    s = c.emu.alloc(len(body) + 1, 4)
    c.emu.wbytes(s, body + b'\0')

    def slot0(em, r):
        tok = _cstr(em, em.arg32(0))
        em.calllog.append(('slot0', 0, em.reg('ecx'), (tok, em.arg32(1) & 0xffffffff)))
        em.ret(eax=0, argbytes=8)

    vt = c.emu.fake_vtable('AddNodes owner', 1, {0: slot0})
    self_obj = c.emu.alloc(0x100, 4)
    c.emu.wbytes(self_obj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.w32(self_obj, vt)
    flag = c.rng.choice([0, 1, c.rng.getrandbits(8), c.rng.getrandbits(32)])
    return [self_obj, s, flag]


S(0x4379f0, 'ZInputAction::AddNodes (high) thiscall', 'thiscall', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 8; allocator and free are logging hooks (GUESS); slot 0 logs the token text')
