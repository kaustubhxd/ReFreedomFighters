"""specs_s739.py - ZOnScreenDisplay::ClassInit2. The engine has the object at +0x190f (slots 0xd8, 0xdc return ints, 0xb4 a
handle) and the db at +0x9b (slots 0x58, 0x134, 0x138). db 0x58 returns the random reference for the value written by the
camera object's slot 0x88, a fixed block for other values, and 0 for that reference in about one case in four. The
reference block carries a dword at +0x676. The objects from 0x134 (slot 0x90) and 0x138 (slot 0x88, 0x25c) log their
arguments. CreateSprites, InitSprites, ZGeomActionMarker::Init and the self slots 0x110 / 0x7c are hooked or faked. mreset
runs as exe code. The mode at +0x360 is 0..5 and the global record gl+0x4ac is a random dword."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _osd(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    gl = _rnd(c, 0x900)
    e.w32(0x7003b8, gl)
    e.w32(gl + 0x4ac, c.rng.getrandbits(32))
    eng = _rnd(c, 0x2000)
    e.w32(0x70039c, eng)
    A = _rnd(c, 0x40)
    e.w32(eng + 0x190f, A)
    db = _rnd(c, 0xb00)
    e.w32(eng + 0x9b, db)

    d8 = c.rng.getrandbits(16)
    dc = c.rng.getrandbits(16)
    bh = c.rng.getrandbits(32)

    def a_d8(em, r):
        log('eng', 0xd8, ())
        em.ret(eax=d8, argbytes=0)

    def a_dc(em, r):
        log('eng', 0xdc, ())
        em.ret(eax=dc, argbytes=0)

    def a_b4(em, r):
        log('eng', 0xb4, (em.arg32(0),))
        em.ret(eax=bh, argbytes=4)
    e.w32(A, e.fake_vtable('eng', 0x200, {0xd8: a_d8, 0xdc: a_dc, 0xb4: a_b4}))

    tval = [c.rng.getrandbits(32)]
    refblk = _rnd(c, 0x800)
    e.w32(refblk + 0x676, c.rng.getrandbits(32))
    xblk = _rnd(c, 0x800)
    ref_pick = [refblk if c.rng.random() < 0.75 else 0]

    def db58(em, r):
        arg = em.arg32(0)
        log('db', 0x58, (arg,))
        if arg == tval[0]:
            em.ret(eax=ref_pick[0], argbytes=4)
        else:
            em.ret(eax=xblk, argbytes=4)

    mp = _rnd(c, 0x40)
    cam = _rnd(c, 0x40)

    def db134(em, r):
        log('db', 0x134, ())
        em.ret(eax=mp, argbytes=0)

    def db138(em, r):
        log('db', 0x138, ())
        em.ret(eax=cam, argbytes=0)
    e.w32(db, e.fake_vtable('db', 0x200, {0x58: db58, 0x134: db134, 0x138: db138}))

    flagval = c.rng.choice([0, 1])

    def mp90(em, r):
        log('mp', 0x90, (em.arg32(0),))
        e.w8(em.arg32(1), flagval)
        em.ret(eax=0, argbytes=8)
    e.w32(mp, e.fake_vtable('mp', 0x100, {0x90: mp90}))

    def cam88(em, r):
        log('cam', 0x88, (em.arg32(0),))
        e.w32(em.arg32(1), tval[0])
        em.ret(eax=0, argbytes=8)
    e.w32(cam, e.fake_vtable('cam', 0x100, {0x88: cam88}))

    def x25c(em, r):
        log('x', 0x25c, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    e.w32(xblk, e.fake_vtable('x', 0x900, {0x25c: x25c}))
    e.w32(refblk, e.fake_vtable('ref', 0x900, {0x25c: x25c}))

    def m110(em, r):
        log('self', 0x110, (em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)

    def m7c(em, r):
        log('self', 0x7c, (nostk(em.arg32(0)), em.rbytes(em.arg32(1), 12)))
        em.ret(eax=0, argbytes=8)

    def h_sprites(name):
        def f(em, r):
            log('osd', name, ())
            em.ret(eax=0, argbytes=0)
        return f

    def h_marker(em, r):
        log('marker', 0x5a8550, (em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    e.hook(0x5a6980, h_sprites(0x5a6980))
    e.hook(0x5a86c0, h_sprites(0x5a86c0))
    e.hook(0x5a8550, h_marker)

    self_ = _rnd(c, 0x2000)
    e.w32(self_, e.fake_vtable('osd', 0x900, {0x110: m110, 0x7c: m7c}))
    e.w32(self_ + 8, c.rng.getrandbits(32))
    e.w32(self_ + 0x360, c.rng.choice([0, 1, 2, 3, 4, 5]))
    e.w32(self_ + 0x52c, c.rng.getrandbits(32))
    e.w32(self_ + 0x530, c.rng.getrandbits(32))
    e.w32(self_ + 0x534, c.rng.getrandbits(32))
    e.w32(self_ + 0x538, c.rng.getrandbits(32))
    return [self_]


S(0x5a6230, 'ZOnScreenDisplay::ClassInit2', 'thiscall', None, ret=None, gen=_osd,
  note='b739 residue 11 [high]; engine, db and object slots fake; CreateSprites/InitSprites/marker hooked')
