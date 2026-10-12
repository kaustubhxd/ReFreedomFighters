"""specs_s724.py - soldier AI batch 724: ZFFActorIf::IsVisible. The argument lists are two-level accessors (object ->
inner object with items at +0 and count at +8; 8-byte items). The actor object (this+0x1c) has fake slots 0x678
(logs the id and the data pointer's value, returns a random result) and 0x12c (logs its argument). RegisterZMsg (db
0x114) logs its name, file and line and returns a random id. The accessor (0x5003d0) and the setter (0x5002f0) run as exe
code; the setter's type-byte check is satisfied by the output items (type byte 0 initially)."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk
from specs_s709 import _log_world


def _list(c, e, items, count):
    """accessor object: +0 -> inner (items at +0, count at +8), +4 = offset 0, +8 = count of the accessor."""
    inner = _rnd(c, 0x20)
    arr = _rnd(c, 8 * max(count, 2))
    for i in range(max(count, 2)):
        e.wbytes(arr + 8 * i, struct.pack('<II', items[i] if i < len(items) else c.rng.getrandbits(32), 0))
    e.w32(inner, arr)
    e.w32(inner + 8, count)
    acc = _rnd(c, 0x20)
    e.w32(acc, inner)
    e.w32(acc + 4, 0)
    e.w32(acc + 8, count)
    return acc


def _iv(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0x100)
    e.w32(db, e.fake_vtable('db', 0x140, {0x114: lambda em, r: (log('db', 0x114, (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3))), em.ret(eax=c.rng.getrandbits(16), argbytes=16))[1]}))
    e.w32(eng + 0x9b, db) if False else e.wbytes(eng + 0x9b, struct.pack('<I', db))

    obj = _rnd(c, 0x40)
    def m678(em, r):
        log('obj', 0x678, (em.arg32(0), em.r32(em.arg32(1))))
        em.ret(eax=c.rng.getrandbits(32), argbytes=8)
    def m12c(em, r):
        log('obj', 0x12c, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    e.w32(obj, e.fake_vtable('obj', 0x500, {0x678: m678, 0x12c: m12c}))

    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, obj)

    inputs = [c.rng.getrandbits(32), c.rng.getrandbits(32)]
    args = _rnd(c, 0x20)
    e.w32(args + 4, _list(c, e, inputs, 2))
    out_items = [0]
    e.w32(args + 8, _list(c, e, out_items, 1))
    return [self_, args]


S(0x55b330, 'ZFFActorIf::IsVisible', 'thiscall', None, ret=None, gen=_iv,
  note='b724 [medium]; accessor and setter run as exe code')
