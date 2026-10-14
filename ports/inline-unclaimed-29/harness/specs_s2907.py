"""specs_s2907.py - unclaimed-29 batch 7 (docs/20-unclaimed-29.md, claim 7, slice 8): ZFFSearchLightGroup::DeleteDebugGeom.
Three fake lists (each: slots +0x4c and +0x44 write 1 through the out pointer; +0x5c writes 1 while its counter lasts and returns
an item; +0xc is plain), fake items (slot +0x210 logs one argument), and the render object at 0x70039c+0x9b+0xadc (slots +0x220 and
+0x240 log one argument). The lists are non-null (the original faults on null). No patch of an exe function, so no flush."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _make_list(c, name, item):
    counter = {'n': c.rng.randint(0, 2)}

    def out_one(tag):
        def h(e, r):
            ptr = e.arg32(0)
            e.calllog.append((name + tag, e.reg('ecx'), ()))
            e.w32(ptr, 1)
            e.ret(eax=0, argbytes=4)
        return h

    def next_item(e, r):
        ptr = e.arg32(0)
        more = 1 if counter['n'] > 0 else 0
        counter['n'] -= 1
        e.calllog.append((name + ':next', e.reg('ecx'), ()))
        e.w32(ptr, more)
        e.ret(eax=item, argbytes=4)

    def plain(e, r):
        e.calllog.append((name + ':end', e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    vt = c.emu.fake_vtable(name, 0x250, {0x4c: out_one(':out4c'), 0x44: out_one(':out44'), 0x5c: next_item, 0xc: plain})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    return obj


def _gen(c):
    def logger(name, nargs):
        def h(e, r):
            e.calllog.append((name, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
            e.ret(eax=0, argbytes=4 * nargs)
        return h
    # item (returned by the lists' +0x5c): slot +0x210 with one argument
    item_vt = c.emu.fake_vtable('item', 0x220, {0x210: logger('item-210', 1)})
    item = _rnd(c, 0x40)
    c.emu.w32(item, item_vt)
    # render object: slots +0x220 and +0x240 with one argument
    rr_vt = c.emu.fake_vtable('render-x', 0x250, {0x220: logger('render-220', 1), 0x240: logger('render-240', 1)})
    rr_obj = _rnd(c, 0x40)
    c.emu.w32(rr_obj, rr_vt)
    rr = _rnd(c, 0x1000)
    c.emu.w32(rr + 0xadc, rr_obj)
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, rr)
    c.emu.w32(0x70039c, rm)
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x50, _make_list(c, 'list-50', item))
    c.emu.w32(self_ + 0x54, _make_list(c, 'list-54', item))
    c.emu.w32(self_ + 0x58, _make_list(c, 'list-58', item))
    return [self_]


S(0x5c6640, 'ZFFSearchLightGroup::DeleteDebugGeom (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-29 batch 7 (slice 8, medium name); three list walks with out flags; render calls 0x220 and 0x240; item 0x210')
