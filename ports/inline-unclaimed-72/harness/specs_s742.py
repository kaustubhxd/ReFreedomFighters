"""specs_s742.py - ZFFHERO::Save (area 72). The hero is a random block; the byte and float fields are written at the
offsets the exe reads. The save object (and a second writer returned by slots 0x60 / 0x4c, so the chained writes are
checked) logs each slot with its arguments. ZPlayer::Save (0x484d20), GameEntity::Save (0x59d3f0) and the two fastcall
helper saves (0x58aa40, 0x58aaf0) are hooked (logged). c_str (0x4cc1d0) comes from the shared logger world. The global
record (0x7003b8) is a random block: the tail uses its pointer value."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s709 import _log_world
from specs_s705 import nostk

BYTE_FIELDS = (0x653, 0x65c, 0x7f0, 0x7f1, 0x7f2, 0x66f, 0x669, 0x66a, 0x66c, 0x66d, 0x66e, 0x67f, 0x831, 0x9f4, 0x9f5,
               0xeec, 0xeed)
FLOAT_FIELDS = (0x7ec, 0x7fb, 0x7ff, 0x803, 0x807, 0x80b, 0x80f, 0x813, 0x817, 0x81b, 0x9e3, 0x451, 0x81f, 0x823, 0xed3,
                0xed7, 0xedb)


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _save(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    gl = _rnd(c, 0x1000)
    e.w32(0x7003b8, gl)
    hero = _rnd(c, 0x1000)
    for off in BYTE_FIELDS:
        e.wbytes(hero + off, bytes([c.rng.getrandbits(8)]))
    for off in FLOAT_FIELDS:
        e.wbytes(hero + off, struct.pack('<f', _f(c.rng.uniform(-500.0, 500.0))))
    e.w32(hero + 0x64f, c.rng.getrandbits(32))
    entity = _rnd(c, 0x100)
    e.w32(hero + 0x54, entity)

    def h_zp(em, r):
        log('hero', 0x484d20, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    def h_ge(em, r):
        log('entity', 0x59d3f0, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    def h_a(em, r):
        log('fastA', 0x58aa40, (nostk(em.reg('ecx')), nostk(em.reg('edx'))))
        em.ret(eax=0, argbytes=0)

    def h_b(em, r):
        log('fastB', 0x58aaf0, (nostk(em.reg('ecx')), nostk(em.reg('edx'))))
        em.ret(eax=0, argbytes=0)
    e.hook(0x484d20, h_zp)
    e.hook(0x59d3f0, h_ge)
    e.hook(0x58aa40, h_a)
    e.hook(0x58aaf0, h_b)

    sub = _rnd(c, 0x40)

    def make_writer(name):
        def slot_fn(slot, ret_obj):
            def f(em, r):
                log(name, slot, (em.arg32(0),))
                em.ret(eax=ret_obj, argbytes=4)
            return f
        return slot_fn

    slots = (0x3c, 0x44, 0x4c, 0x54, 0x5c, 0x60, 0x64, 0x68, 0x70)
    mk = make_writer('save')
    sub_mk = make_writer('sub')
    save = _rnd(c, 0x40)
    save_tbl = {}
    sub_tbl = {}
    for s_ in slots:
        ret = sub if s_ in (0x60, 0x4c) else 0
        save_tbl[s_] = mk(s_, ret)
        sub_tbl[s_] = sub_mk(s_, sub if s_ in (0x60, 0x4c) else 0)
    e.w32(save, e.fake_vtable('save', 0x100, save_tbl))
    e.w32(sub, e.fake_vtable('sub', 0x100, sub_tbl))

    self_ = hero
    return [self_, save]


S(0x5947b0, 'ZFFHERO::Save', 'thiscall', None, ret='al', gen=_save,
  note='b742 area 72 [high]; ZPlayer::Save / GameEntity::Save / helper saves hooked; chained writes checked via sub writer')
