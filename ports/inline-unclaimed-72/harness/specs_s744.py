"""specs_s744.py - CEntityTracker::Load (area 72 slice 0). The load object's slots log their pointer or value; slot 0x40
writes a random dword into its pointer argument. The engine db (0x9b) maps an id to a random reference and logs it. Operator
new (0x41e290, cdecl) is hooked to return two prepared blocks in order (the record array and the id array), each big enough
for the record count (0..5). Count at +0x54 is 0..5."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _ctl(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    refs = {}

    def db58(em, r):
        ident = em.arg32(0)
        log('db', 0x58, (ident,))
        em.ret(eax=refs.setdefault(ident, c.rng.getrandbits(32)), argbytes=4)
    e.w32(db, e.fake_vtable('db', 0x100, {0x58: db58}))

    count = c.rng.randint(0, 5)
    blocks = [_rnd(c, max(0x17 * 6, 0x20)), _rnd(c, 0x40)]

    def h_new(em, r):
        size = em.arg32(0)
        e.calllog.append(('heap', 0x41e290, None, (nostk(size),)))
        em.ret(eax=blocks.pop(0), argbytes=0)
    e.hook(0x41e290, h_new)

    load = _rnd(c, 0x40)

    def l40(em, r):
        p = em.arg32(0)
        log('load', 0x40, ())
        e.w32(p, c.rng.getrandbits(32))
        em.ret(eax=0, argbytes=4)

    def ln(slot):
        def f(em, r):
            log('load', slot, (nostk(em.arg32(0)),))
            em.ret(eax=0, argbytes=4)
        return f
    tbl = {slot: ln(slot) for slot in range(0x00, 0x80, 4)}
    tbl[0x40] = l40
    e.w32(load, e.fake_vtable('load', 0x100, tbl))

    self_ = _rnd(c, 0x100)
    e.w32(self_ + 4, c.rng.getrandbits(32))
    e.w32(self_ + 0x54, count)
    e.w32(self_ + 0x50, 0)
    e.w32(self_ + 0x4c, 0)
    return [self_, load]


S(0x5c06c0, 'CEntityTracker::Load', 'thiscall', None, ret='al', gen=_ctl,
  note='b744 area 72 slice 0 [high]; operator new hooked (two prepared blocks); load and db slots fake')
