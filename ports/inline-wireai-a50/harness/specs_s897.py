"""specs_s897.py - gap-band slice, batch 897: 0x41ec30 (ZSysMem::NewRef), thiscall, one stack arg (pointer), ret 4, returns al.
Stand-ins: the object at this+4 (slot +0x10: a bool drawn at generation time, one argument), the logger global 0x70038c (drawn null
or a fake object with slot +0x30: three words, callee pops 12). The table at this+0x28 is in the heap and compared. The object's mask
is drawn small so the table index stays in range. Null object, false and true branches all run."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    verdict = r.random() < 0.7

    def h10(e, rr):
        e.calllog.append(('obj.10', e.arg32(0)))
        e.ret(eax=1 if verdict else 0, argbytes=4)

    def h30(e, rr):
        e.calllog.append(('log.30', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=12)

    if r.random() < 0.7:
        logger = vt_object(c, 0x20, {0x30: h30}, nslots=0x20, name='logger')
        e.w32(0x70038c, logger)
    else:
        e.w32(0x70038c, 0)
    self = rnd(c, 0x100)
    if r.random() < 0.15:
        e.w32(self + 4, 0)
    else:
        obj = vt_object(c, 0x40, {0x10: h10}, nslots=0x20, name='obj')
        e.w32(obj + 0x10, r.randint(0, 0xff))
        e.w32(self + 4, obj)
    table = rnd(c, 0x400)
    e.w32(self + 0x28, table)
    p = r.choice([0, 1, 0x80, 0xff, r.getrandbits(32)])
    return [self, p]


S(0x41ec30, 'ZSysMem::NewRef (named)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch897 (band slice)')
