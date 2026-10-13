"""specs_s345.py - gap band batch 345: 0x41e170 forwards its two cdecl arguments to strchr (IAT 0x676254, VCRUNTIME140). The
import is stubbed with a deterministic strchr over the emulated memory (first occurrence of the byte c, or NULL). The string is
random printable bytes with a NUL; c is drawn from the string or from outside it."""
from pilot import S
import engine_stubs as E


def _strchr(em, rr):
    s = em.arg32(0)
    ch = em.arg32(1) & 0xff
    i = 0
    while True:
        b = em.rbytes(s + i, 1)[0]
        if b == ch:
            em.ret(eax=s + i, argbytes=0)
            return
        if b == 0:
            em.ret(eax=0, argbytes=0)
            return
        i += 1


def _hook(c):
    c.emu.stub_import('strchr', _strchr)


def _gen(c):
    r = c.rng
    n = r.randrange(0, 20)
    s = c.emu.alloc(n + 1, 1)
    body = bytes(r.randrange(65, 123) for _ in range(n)) + b'\0'
    c.emu.wbytes(s, body)
    if n and r.random() < 0.7:
        ch = body[r.randrange(n)]
    else:
        ch = r.randrange(0, 256)
    c.emu.mu.ctl_flush_tb()
    return [s, ch]


S(0x41e170, 'strchr forwarder (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_hook,
  note='gap band batch 345; strchr import stubbed')
