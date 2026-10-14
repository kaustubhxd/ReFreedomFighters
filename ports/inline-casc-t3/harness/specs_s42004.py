"""specs_s42004.py - batch 42004. 0x526f20: slot 0x2c of this returns a float on st0; logger 0x700390 slot 0x20 (callee pops 8, returns a log object) and
log object slot 0x2c (cdecl printf-like, caller pops) as in the AI specs; unaligned fields +0x19 (flag), +0x25 (float), +0x10 and +0xc written as bytes."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fb(r, small=False):
    ch = [r.uniform(-1, 1), r.uniform(-100, 100), r.uniform(-1e-3, 1e-3), 0.0, -0.0, 1e-6, r.uniform(-1e5, 1e5), float('nan')]
    if small:
        ch = [r.uniform(-1, 1), r.uniform(-1e-3, 1e-3), r.uniform(-0.1, 0.1), 0.0, r.uniform(-100, 100)]
    return struct.pack('<f', r.choice(ch))


def _logger(c):
    e = c.emu
    logobj = rnd(c, 16)

    def printf(em, res_):
        args = tuple(em.arg32(k) for k in range(2))
        em.calllog.append(('log.printf', 0x2c, args))
        em.ret(eax=0, argbytes=0)
    lvt = e.fake_vtable('log', 16, {0x2c: printf})
    e.w32(logobj, lvt)
    vt = e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2})
    lg = rnd(c, 16)
    e.w32(lg, vt)
    e.w32(0x700390, lg)


def g526f20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logger(c)
    me = obj(c, 0x60, {0x2c: pystub(c, 0, this=True, pop=0, st0=lambda em, k: r.uniform(-100, 100))})
    e.wbytes(me + 0x19, (bytes(4) if r.random() < 0.8 else bytes(r.getrandbits(8) for _ in range(4))))
    e.wbytes(me + 0x25, _fb(r, small=r.random() < 0.5))
    e.wbytes(me + 0x10, _fb(r))
    e.wbytes(me + 0xc, bytes(r.getrandbits(8) for _ in range(4)))
    return [me]


S(0x526f20, 'GUESS one-shot trigger with logger assert', 'thiscall', None, ret=None, gen=g526f20, note='batch42004')
