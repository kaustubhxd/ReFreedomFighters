"""specs_s33055.py - h3 () batch 33055."""
import pe_emu
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g487030(c):
    clear_hooks(c)
    e = c.emu
    s3a = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    s3b = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    a = obj(c, 0x80, {0x3c: s3a})
    vt2 = e.alloc(0x80, 4)
    e.w32(vt2 + 0x3c, s3b)
    s4c = pystub(c, 1, this=True, side=lambda em, k: e.w32(a, vt2), ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x4c: s4c})
    return [rnd(c, 0x40), a]


def _g4ab9b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e6330, 1, this=True)
    sc = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0xc, sc)
    me = rnd(c, 0x100)
    e.w32(me + 0x6e, vt)
    e.wbytes(me + 4, bytes([r.choice([0, 1, 2, 3, 0xfd, r.getrandbits(8)])]))
    return [me, rnd(c, 0x40)]


def _g533bf0(c):
    clear_hooks(c)
    hook_rec(c, 0x539730, 1, this=True)
    s8 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    return [rnd(c, 0x40), obj(c, 0x80, {8: s8})]


def _g55baa0(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: rnd(c, 0x10))
    s = pystub(c, 3, this=True, ret=lambda em, k: _w(c))
    me = rnd(c, 0x80)
    e.w32(me + 0x1c, obj(c, 0x700, {0x6e8: s}))
    a = rnd(c, 0x20)
    return [me, a]


def _g5ef520(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x100)

    def mk(i):
        s = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('o', i)), ret=lambda em, k: _w(c))
        return obj(c, 0x40, {8: s})
    for i, off in enumerate((0xa9, 0xa1, 0xa5)):
        e.w32(me + off, mk(i))
    e.w32(me + 0xb1, r.choice([mk(3), mk(3), 0]))
    return [me]


def _g605110(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slog = pystub(c, 3, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return []


def _g467740(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x200)
    s1 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    s2 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    o1 = obj(c, 0x40, {4: s1})
    o2 = obj(c, 0x40, {4: s2})
    e.w32(o1 + 4, r.choice([0, 0, _w(c)]))
    e.w32(me + 0x1ce, o1)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.w32(me + 0x1ce, o2)
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [me]


def _g42333d(c):
    clear_hooks(c)
    e = c.emu
    s3c = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x3c, s3c)
    try:
        e.mu.mem_map(0xcccc0000, 0x10000)
    except Exception:
        pass
    e.w32(0xcccccccc, vt)
    e.w32(0xccccccd0, _w(c))
    hook_rec(c, 0x42ac56, 4, pop=0, ret=lambda em, k: _w(c))
    e.w32(0x6761bc, pystub(c, 4, ret=lambda em, k: _w(c)))
    return []


S(0x487030, 'GUESS table vcall 4c then arg vtable 3c', 'thiscall', None, ret='eax', gen=_g487030, note='batch33055')
S(0x4ab9b0, 'GUESS subobject vcall c then call unless flag', 'thiscall', None, ret=None, gen=_g4ab9b0, note='batch33055')
S(0x533bf0, 'GUESS arg vcall 8 then call return 1', 'thiscall', None, ret='al', gen=_g533bf0, note='batch33055')
S(0x55baa0, 'GUESS lookup byte then vcall 6e8', 'thiscall', None, ret='eax', gen=_g55baa0, note='batch33055')
S(0x5ef520, 'GUESS release four children', 'thiscall', None, ret=None, gen=_g5ef520, note='batch33055')
S(0x605110, 'GUESS global log call then assert', 'cdecl', None, ret='eax', gen=_g605110, note='batch33055')
S(0x467740, 'GUESS maybe assert then tail vcall reread', 'thiscall', None, ret='eax', gen=_g467740, note='batch33055')
S(0x42333d, 'GUESS SEH funclet sprintf and import', 'cdecl', None, ret='eax', gen=_g42333d, note='batch33055')
