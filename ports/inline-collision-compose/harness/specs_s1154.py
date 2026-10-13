"""specs_s1154.py - collision thread batch 1154 (GUESS name): 0x4fbe20, CMAINCAMERACONTROL::Command. Nine command words sit at fixed
offsets of this (distinct values); the command is one of them or an unknown word. Fakes (all logged): the sub-object at +0x98
(slots 4 and 0x3c, one argument), this's own slot 0x84 (two arguments), the object at +0x44 (slot 0x12c, three arguments), the
object at +0x84 with a list at +0x48 (records: value, next at +0xc), and the sys object's slot 0xbc, which returns an object whose
slot 0x58 returns a float in ST0. The stored-to argument is a valid buffer in most cases."""
import struct
from pilot import S, F

OFFS = {0x90: 0x0101, 0x92: 0x0102, 0x8e: 0x0103, 0x82: 0x0104, 0x72: 0x0105, 0x8a: 0x0106, 0x8c: 0x0107, 0x14c: 0x0108, 0x96: 0x0109}


def _cmd(c):
    e, r = c.emu, c.rng
    fv = r.uniform(-50, 50)

    def sub4(em, rr):
        em.calllog.append(('sub4', em.arg32(0)))
        em.ret(argbytes=4)

    def sub3c(em, rr):
        em.calllog.append(('sub3c', em.arg32(0)))
        em.ret(argbytes=4)

    subvt = e.fake_vtable('sub_4fbe20', 0x20, {4: sub4, 0x3c: sub3c})

    def s84(em, rr):
        em.calllog.append(('84', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)
    selfvt = e.fake_vtable('self_4fbe20', 0x30, {0x84: s84})

    def s12c(em, rr):
        em.calllog.append(('12c', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(argbytes=12)
    o44vt = e.fake_vtable('o44_4fbe20', 0x80, {0x12c: s12c})
    o44 = e.alloc(0x40, 4)
    e.w32(o44, o44vt)

    def s58(em, rr):
        em.calllog.append(('58', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8, st0=fv)
    retvt = e.fake_vtable('ret_4fbe20', 0x30, {0x58: s58})
    retobj = e.alloc(0x40, 4)
    e.w32(retobj, retvt)

    def sbc(em, rr):
        em.ret(eax=retobj, argbytes=0)
    sysvt = e.fake_vtable('sys_4fbe20', 0x40, {0xbc: sbc})
    sysobj = e.alloc(0x100, 16)
    e.wbytes(sysobj, bytes(r.getrandbits(8) for _ in range(0x100)))
    e.w32(sysobj, sysvt)
    e.w32(0x70039c, sysobj)

    # the list: entries with a value at +0 and a next pointer at +0xc
    recs = [e.alloc(0x20, 4) for _ in range(r.randrange(0, 4))]
    for i, rc in enumerate(recs):
        e.w32(rc, r.getrandbits(32))
        e.w32(rc + 0xc, recs[i + 1] if i + 1 < len(recs) else 0)
    P = e.alloc(0x60, 4)
    e.wbytes(P, bytes(r.getrandbits(8) for _ in range(0x60)))
    e.w32(P + 0x48, recs[0] if recs else 0)

    self_ = e.alloc(0x200, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
    e.w32(self_, selfvt)
    e.w32(self_ + 0x98, subvt)                 # the field IS the vtable pointer (the exe calls [[this+0x98]+4])
    e.w32(self_ + 0x44, o44)
    e.w32(self_ + 0x84, P)
    for off, v in OFFS.items():
        e.w16(self_ + off, v)
    cmd = r.choice(list(OFFS.values()) + [0x0fff])
    arg_buf = e.alloc(0x10, 4)
    e.wbytes(arg_buf, bytes(r.getrandbits(8) for _ in range(0x10)))
    argv = arg_buf if r.random() < 0.8 else 0
    arg = argv if cmd == 0x0103 else r.getrandbits(32)
    return [self_, cmd, arg]


S(0x4fbe20, 'CMAINCAMERACONTROL::Command: nine command words; stores, the list walk, the float from the sys object (name GUESS)',
  'thiscall', None, ret='eax', gen=_cmd, note='batch1154')
