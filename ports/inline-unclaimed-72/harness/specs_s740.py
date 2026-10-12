"""specs_s740.py - ZMatPosAnim::Init. The object at +0x44 has a fake vtable (0x4c returns the tag's object, 0x80, 0x94, 0x74,
0x40 and 0x3c log their arguments, 0x20 returns an inner object with slot 0x94 and 0x74). Its +0x10 points to a block whose
+0x18 dword gets |= 2. The run object is the fake this+0x48: its exe calls (Create, Run, SetFrameStart/End) and the helpers
0x43e960, 0x4de4f0 and RegisterMessages are hooked, logging their arguments; Run returns a random float on st0. vmmul,
PSVECAdd and mreset run as exe code. The engine frame counter (+0x40) is random. The byte flags are random; the self vtable
slot 0x68 logs."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _mpi(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x40, c.rng.randint(0, 100000))

    rset = c.rng.getrandbits(32)
    inner = _rnd(c, 0x100)
    rfl = c.rng.random()

    def o94(em, r):
        log('inner', 0x94, (nostk(em.arg32(0)), nostk(em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def o74(em, r):
        log('inner', 0x74, (nostk(em.arg32(0)), nostk(em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    e.w32(inner, e.fake_vtable('inner', 0x200, {0x94: o94, 0x74: o74}))

    sub = _rnd(c, 0x40)
    obj = _rnd(c, 0x100)

    def o4c(em, r):
        log('obj', 0x4c, (em.arg32(0),))
        em.ret(eax=rset, argbytes=4)

    def o80(em, r):
        log('obj', 0x80, (nostk(em.arg32(0)), nostk(em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def o20(em, r):
        log('obj', 0x20, ())
        em.ret(eax=inner, argbytes=0)

    def o40(em, r):
        log('obj', 0x40, ())
        em.ret(eax=0, argbytes=0)

    def o3c(em, r):
        log('obj', 0x3c, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    def o74(em, r):
        log('obj', 0x74, (em.rbytes(em.arg32(0), 36), em.rbytes(em.arg32(1), 12)))
        em.ret(eax=0, argbytes=8)
    e.w32(obj, e.fake_vtable('obj', 0x200, {0x4c: o4c, 0x80: o80, 0x20: o20, 0x40: o40, 0x3c: o3c, 0x74: o74}))
    e.w32(obj + 0x10, sub)
    e.w32(sub + 0x18, c.rng.getrandbits(32))

    self_ = _rnd(c, 0x200)
    e.w32(self_, e.fake_vtable('self', 0x200, {0x68: lambda em, r: (log('self', 0x68, (em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=8))[1]}))
    e.w32(self_ + 0x44, obj)
    e.wbytes(self_ + 0xc4, bytes([c.rng.choice([0, 1])]))
    e.wbytes(self_ + 0xc5, bytes([c.rng.choice([0, 1])]))
    e.wbytes(self_ + 0xc6, bytes([c.rng.choice([0, 1, 1])]))
    e.wbytes(self_ + 0xcb, bytes([c.rng.choice([0, 1])]))
    e.wbytes(self_ + 0xc7, struct.pack('<f', _f(c.rng.uniform(-10.0, 10.0))))
    e.w32(self_ + 0xcc, c.rng.choice([0, 0, 5, 77]))
    e.w32(self_ + 0xd0, c.rng.choice([0, 0, 9, 250]))
    e.wbytes(self_ + 0x93, b''.join(struct.pack('<f', _f(c.rng.uniform(-3.0, 3.0))) for _ in range(3)))
    e.wbytes(self_ + 0x5f, b''.join(struct.pack('<f', _f(c.rng.uniform(-3.0, 3.0))) for _ in range(3)))

    run = self_ + 0x48

    def h_create(em, r):
        log('run', 0xc, (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=0, argbytes=16)

    def h_run(em, r):
        log('run', 0x0, (em.arg32(0), nostk(em.arg32(1)), nostk(em.arg32(2)), em.arg32(3)))
        em.ret(st0=_f(c.rng.uniform(-1.0, 1.0)), argbytes=16)

    def h_sfs(em, r):
        log('run', 0x1, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    def h_sfe(em, r):
        log('run', 0x2, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    def h_43(em, r):
        log('h43', 0x43e960, (nostk(em.reg('ecx')), em.rbytes(em.reg('edx'), 12)))
        em.ret(eax=0, argbytes=0)

    def h_4d(em, r):
        log('h4d', 0x4de4f0, (nostk(em.reg('ecx')), em.rbytes(em.reg('edx'), 36)))
        em.ret(eax=0, argbytes=0)

    def h_reg(em, r):
        log('reg', 0x4a5c20, ())
        em.ret(eax=0, argbytes=0)
    e.hook(0x4e7880, h_create)
    e.hook(0x4e7930, h_run)
    e.hook(0x4e7ce0, h_sfs)
    e.hook(0x4e7c50, h_sfe)
    e.hook(0x43e960, h_43)
    e.hook(0x4de4f0, h_4d)
    e.hook(0x4a5c20, h_reg)
    return [self_]


S(0x4a5930, 'ZMatPosAnim::Init', 'thiscall', None, ret=None, gen=_mpi,
  note='b740 residue 11 [high]; run object calls and helpers hooked; vmmul/PSVECAdd/mreset exe')
