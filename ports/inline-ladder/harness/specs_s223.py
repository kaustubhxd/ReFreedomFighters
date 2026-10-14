"""specs_s223.py - ladder thread batch 223: ZIKLNKOBJ members, part 2."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _self(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x200)
    rv = {o: r.getrandbits(32) for o in (0x21c, 0x32c, 0x84, 0x3dc, 0x414)}
    slots = {0x21c: (1, lambda e2, a: (rv[0x21c], None, None)), 0x32c: (1, lambda e2, a: (rv[0x32c], None, None)),
             0x84: (1, lambda e2, a: (rv[0x84], None, K.bits3(e2, a[0]))),
             0x3dc: (0, lambda e2, a: (0, None, None)), 0x414: (0, lambda e2, a: (0, None, None))}
    e.w32(s, K.vt(c, 'self', slots, nslots=0x110))

    def hk(addr, name, n, ab):
        def h(e2, res):
            e2.calllog.append((name, e2.reg('ecx'), tuple(e2.arg32(i) for i in range(n))))
            e2.ret(eax=0x7070 + n, argbytes=ab)
        e.hook(addr, h)
    hk(0x462040, 'ZLNKOBJ::CopyDataBlock', 1, 4)
    hk(0x4e1b30, 'DBLK::NextBlock', 0, 0)
    hk(0x4620d0, 'ZLNKOBJ::CopyGeometryFrom', 1, 4)
    hk(0x466220, 'ZTARGET::Clear', 0, 0)
    eng = K.engine(c)
    k = r.random()
    e.wf32(eng + 0x48, f32(r.uniform(0, 0.1)) if k < 0.8 else c.fv())
    e.wf32(s + 0x1c6, f32(r.uniform(0, 1.2)) if k < 0.9 else c.fv())
    if r.random() < 0.15:          # land exactly on the 1.0 clamp edge
        e.wf32(eng + 0x48, 0.0)
        e.wf32(s + 0x1c6, 1.0)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    holder = K.rnd(c, 0x10)
    lst = r.getrandbits(32)
    e.w32(holder, K.vt(c, 'lists', {0x25c: (2, lambda e2, a: (lst, None, None))}, nslots=0xb0))
    e.w32(d + 0xadc, holder)
    gobj = K.rnd(c, 0x500)
    e.w32(0x7003b8, gobj)
    return s


def g(n, buf=False):
    def f(c):
        s = _self(c)
        if buf:
            return [s, c.fbuf(3)]
        return [s] + [c.rng.getrandbits(32) for _ in range(n)]
    return f


S(0x466340, 'ZIKLNKOBJ::CopyDataBlock', 'thiscall', None, ret='eax', gen=g(1), note='batch223')
S(0x466630, 'ZIKLNKOBJ::FindBestAnim', 'thiscall', None, ret='eax', gen=g(1), note='batch223')
S(0x466360, 'ZIKLNKOBJ::CopyGeometryFrom', 'thiscall', None, ret=None, gen=g(1), note='batch223')
S(0x466800, 'ZIKLNKOBJ::GetFocalPoint', 'thiscall', None, ret='eax', gen=g(0, True), note='batch223')
S(0x466d90, 'ZIKLNKOBJ::Load2', 'thiscall', None, ret=None, gen=g(0), note='batch223')
S(0x467a40, 'ZIKLNKOBJ::SetHeadTarget', 'thiscall', None, ret=None, gen=g(0, True), note='batch223')
S(0x467710, 'ZIKLNKOBJ::Reset', 'thiscall', None, ret=None, gen=g(0), note='batch223')
