"""specs_s728.py - soldier AI batch 728: ZTargetObtained2 (Command, Init2, FrameUpdate, CopyEventDataBlock). The object has a
fake vtable with slot 0x68 (logs its arguments). The engine's level controller (gl+0x2c15) is present in most cases; its
unique-bit functions 0x59d130 / 0x59d150 / 0x59d250 and SendNotify 0x5b7ad0 are hooked (logged, fixed results per case). The
DBREAD operators 0x4e5e40 / 0x4e5e60 are hooked and return the next values from a per-case list. All hooks and closures are
built inside gen, so each run gets its own copies."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s709 import _log_world
from specs_s705 import nostk


def _base(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    gl = _rnd(c, 0x2c20)
    e.w32(0x7003b8, gl)
    ctrl = _rnd(c, 0x40) if c.rng.random() < 0.8 else 0
    e.w32(gl + 0x2c15, ctrl)

    idv = c.rng.getrandbits(32)
    flag = c.rng.choice([0, 1])

    def h130(em, r):
        log('ctrl', 0x59d130, (em.arg32(0),))
        em.ret(eax=idv, argbytes=4)

    def h150(em, r):
        log('ctrl', 0x59d150, (em.arg32(0), em.arg32(1)))
        em.ret(eax=flag, argbytes=8)

    def h250(em, r):
        log('ctrl', 0x59d250, (em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)

    def hnotify(em, r):
        log('tgt', 0x5b7ad0, ())
        em.ret(eax=0, argbytes=0)

    e.hook(0x59d130, h130)
    e.hook(0x59d150, h150)
    e.hook(0x59d250, h250)
    e.hook(0x5b7ad0, hnotify)

    def f68(em, r):
        log('tgt', 0x68, (em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)

    self_ = _rnd(c, 0x60)
    e.w32(self_, e.fake_vtable('tgt', 0x80, {0x68: f68}))
    e.w32(self_ + 0x48, c.rng.getrandbits(32))
    cmd = c.rng.getrandbits(16)
    e.wbytes(self_ + 0x4c, struct.pack('<H', cmd))
    return self_, e, c, cmd


def _cmd(c):
    self_, e, c, cmd = _base(c)
    arg = cmd if c.rng.random() < 0.6 else c.rng.getrandbits(16)
    data = _rnd(c, 0x10)
    return [self_, arg, data]


def _init2(c):
    self_, e, c, _ = _base(c)
    return [self_]


def _fu(c):
    self_, e, c, _ = _base(c)
    return [self_]


def _cev(c):
    self_, e, c, _ = _base(c)
    e_ = e
    a = c.rng.getrandbits(16)
    b = c.rng.getrandbits(32)
    d = c.rng.getrandbits(16)
    w16 = [a, d]
    rd = _rnd(c, 0x10)

    def op16(em, r):
        em.ret(eax=w16.pop(0), argbytes=0)

    def op32(em, r):
        em.ret(eax=b, argbytes=0)

    e.hook(0x4e5e40, op16)
    e.hook(0x4e5e60, op32)
    return [self_, rd]


S(0x5b7a10, 'ZTargetObtained2::Command', 'thiscall', None, ret='eax', gen=_cmd, note='b728 [high]; controller hooked')
S(0x5b7aa0, 'ZTargetObtained2::Init2', 'thiscall', None, ret=None, gen=_init2, note='b728 [high]; controller hooked')
S(0x5b7a70, 'ZTargetObtained2::FrameUpdate', 'thiscall', None, ret=None, gen=_fu, note='b728 [high]; controller and SendNotify hooked')
S(0x5b7a40, 'ZTargetObtained2::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_cev, note='b728 [high]; DBREAD hooked')
