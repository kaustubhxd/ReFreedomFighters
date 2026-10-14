"""specs_s823.py - animation layer thread, batch 823: ZLNKOBJ::CloseObjMatBone and InitObjMatBone."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, vslot


def _env(c, count, mod):
    e, r = c.emu, c.rng
    defs = vt_object(c, 0x20, {0xb0: vslot('defs.Count', 1, ret=count)}, name='defs')
    s = vt_object(c, 0x20, {0x8c: vslot('mgr.Modifier', 1, ret=mod)}, name='defsmgr')
    e.w32(s + 0x18, defs)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x1aa3, s)
    e.w32(0x70039c, g)
    geom = rnd(c, 0x80)
    e.w32(geom + 0x6c, r.randint(0, 50))
    return geom


def _alloc(e, res):
    sz = e.arg32(0)
    e.calllog.append(('new', sz))
    e.ret(eax=e.alloc(sz, 8) if sz < 0x100000 else 0, argbytes=0)   # cdecl: caller pops


def _del(e, res):
    e.calllog.append(('delete', e.arg32(0) != 0, e.arg32(1)))
    e.ret(eax=0, argbytes=0)   # cdecl


def _memset(e, res):
    d, v, n = e.arg32(0), e.arg32(1), e.arg32(2)
    e.calllog.append(('memset', d - 0x20000000 if 0x20000000 <= d < 0x30000000 else 'x', v & 0xff, n))
    if n:
        e.wbytes(d, bytes([v & 0xff]) * n)
    e.ret(eax=d, argbytes=0)   # cdecl


def _close(c):
    only_hooks(c, {0x634273: _del})
    e, r = c.emu, c.rng
    _env(c, 0, 0)
    lst = [rnd(c, 0x80) for _ in range(r.randint(0, 4))]
    for n in lst:
        ob = vt_object(c, 0x20, {0: vslot('extra.dtor', 1)}, name='extra')
        e.w32(n + 0x70, ob if r.random() < 0.7 else 0)
    st = {'pos': 0}

    def begin(e, res):
        st['pos'] = 0
        e.ret(eax=0, argbytes=4)

    def nxt(e, res):
        v = lst[st['pos']] if st['pos'] < len(lst) else 0
        st['pos'] += 1
        e.ret(eax=v, argbytes=4)
    lobj = vt_object(c, 0x20, {0x4c: begin, 0x64: nxt, 0: vslot('list.dtor', 1)}, name='nodelist')
    self = vt_object(c, 0x100, {}, nslots=0x30, name='self')
    e.w32(self + 0x18, lobj if r.random() < 0.8 else 0)
    e.w32(self + 0x1c, rnd(c, 0x40) if r.random() < 0.8 else 0)
    e.w32(self + 0x6c, vt_object(c, 0x20, {0x2c: vslot('mod.dtor', 1)}, name='mod') if r.random() < 0.8 else 0)
    return [self]


def _init(c):
    only_hooks(c, {0x41e290: _alloc, 0x634d10: _memset})
    e, r = c.emu, c.rng
    count = r.choice([0, 1, 5, 12, 0x40, r.randint(0, 200)])
    mod = vt_object(c, 0x20, {0x58: vslot('mod.Attach', 1, ret=rnd(c, 0x20))}, name='mod')
    geom = _env(c, count, mod)
    self = vt_object(c, 0x100, {0x2cc: vslot('self.Defs', 0, ret=rnd(c, 0x40)),
                                0x284: vslot("self.SetDefs", 2)}, nslots=0xc0, name="self")
    e.w32(self + 8, geom)
    return [self]


S(0x461f00, 'ZLNKOBJ::CloseObjMatBone', 'thiscall', None, gen=_close, note='batch823; delete hooked')
S(0x463430, 'ZLNKOBJ::InitObjMatBone', 'thiscall', None, gen=_init, note='batch823; new/memset hooked')
