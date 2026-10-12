"""specs_s745.py - ZActionPushButton::Execute (area 72 slice 0). Objects: A (+8) slot 0x80 writes 8 floats and 3 floats, B
(+0xc) slot 0x384 writes 3 + 3 floats, slot 0x8c and 0x228 log, D (+0x10) slot 0x1c logs its 8 dword arguments. The float
values are random in about [-150, 150] with magnitudes that cover both sides of each compare, and some zeros. PSVECSubtract
(0x43e920) and vmtmul (0x441a60) run as exe code. The logger and c_str come from the shared logger world."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s709 import _log_world
from specs_s705 import nostk


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _vals(c, n):
    out = []
    for _ in range(n):
        r = c.rng.random()
        if r < 0.1:
            out.append(0.0)
        else:
            out.append(_f(c.rng.uniform(-150.0, 150.0)))
    return out


def _pb(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    def A80(em, r):
        out40, out10 = em.arg32(0), em.arg32(1)
        e.wbytes(out40, struct.pack('<8f', *_vals(c, 8)))
        e.wbytes(out10, struct.pack('<3f', *_vals(c, 3)))
        log('A', 0x80, ())
        em.ret(eax=0, argbytes=8)

    def B384(em, r):
        out64, out1c = em.arg32(0), em.arg32(1)
        e.wbytes(out64, struct.pack('<3f', *_vals(c, 3)))
        e.wbytes(out1c, struct.pack('<3f', *_vals(c, 3)))
        log('B', 0x384, ())
        em.ret(eax=0, argbytes=8)

    def B8c(em, r):
        log('B', 0x8c, (nostk(em.arg32(0)),))
        em.ret(eax=0, argbytes=4)

    def B228(em, r):
        log('B', 0x228, tuple(em.arg32(k) for k in range(5)))
        em.ret(eax=0, argbytes=20)

    def D1c(em, r):
        log('D', 0x1c, tuple(em.arg32(k) for k in range(8)))
        em.ret(eax=0, argbytes=32)

    def h_sub(em, r):
        out = em.reg('ecx')
        a = em.reg('edx')
        b = em.arg32(0)
        av = struct.unpack('<3f', em.rbytes(a, 12))
        bv = struct.unpack('<3f', em.rbytes(b, 12))
        log('sub', 0x43e920, (nostk(out), av, bv))
        e.wbytes(out, struct.pack('<3f', *[av[i] - bv[i] for i in range(3)]))
        em.ret(eax=out, argbytes=4)

    def h_vm(em, r):
        out = em.reg('ecx')
        m = em.reg('edx')
        mv = struct.unpack('<12f', em.rbytes(m, 48))
        log('vm', 0x441a60, (nostk(out), mv[:3]))
        e.wbytes(out, struct.pack('<3f', mv[0], mv[1] * 0.5, mv[2]))
        em.ret(eax=out, argbytes=0)

    A = _rnd(c, 0x40)
    e.w32(A, e.fake_vtable('A', 0x200, {0x80: A80}))
    B = _rnd(c, 0x40)
    e.w32(B, e.fake_vtable('B', 0x300, {0x384: B384, 0x8c: B8c, 0x228: B228}))
    D = _rnd(c, 0x40)
    e.w32(D, e.fake_vtable('D', 0x100, {0x1c: D1c}))

    self_ = _rnd(c, 0x100)
    e.w32(self_ + 8, A)
    e.w32(self_ + 0xc, B)
    e.w32(self_ + 0x10, D)
    e.w32(self_ + 0x14, c.rng.getrandbits(32))
    return [self_]


S(0x486700, 'ZActionPushButton::Execute', 'thiscall', None, ret='al', gen=_pb,
  note='b745 area 72 slice 0 [high]; A/B/D vtables fake; PSVECSubtract and vmtmul exe')
