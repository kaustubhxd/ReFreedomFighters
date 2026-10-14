"""specs_s929.py - batch 929: 0x4388a0 (ZInputAction::FreeActionDependencies, thiscall, no args). The list object at this+0x3e: slot +0x4c (one
arg, writes a drawn dword), slot +0x64 (one arg, returns a pointer to a cell that is drawn null or a cell holding a drawn dword; the cell is
returned on the first n calls, then null), slot 0 (scalar deleting dtor, one arg). 0x634273 (cdecl, two words) is stood in. The null list and the
non-null list are both drawn; the word this+0x3e is compared after the call."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    n = r.randint(0, 3)
    cells = []
    for _ in range(n):
        cell = rnd(c, 8)
        e.w32(cell, r.choice([0, r.getrandbits(32)]))
        cells.append(cell)
    k = [0]

    def h4c(e, rr):
        e.calllog.append(('L.4c', e.arg32(0) != 0))
        e.w32(e.arg32(0), 0x1234)
        e.ret(eax=0, argbytes=4)

    def h64(e, rr):
        i = k[0]
        k[0] += 1
        p = cells[i] if i < len(cells) else 0
        e.calllog.append(('L.64', p != 0))
        e.ret(eax=p, argbytes=4)

    def h0(e, rr):
        e.calllog.append(('L.0', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h273(e, rr):
        e.calllog.append(('634273', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x634273: h273})
    lst = vt_object(c, 0x40, {0x0: h0, 0x4c: h4c, 0x64: h64}, nslots=0x40, name='list')
    self = rnd(c, 0x80)
    if r.random() < 0.2:
        e.w32(self + 0x3e, 0)
    else:
        e.w32(self + 0x3e, lst)
    return [self]


S(0x4388a0, 'ZInputAction::FreeActionDependencies (named)', 'thiscall', None, ret=None, gen=_gen, note='area50 batch929 (core slice)')
