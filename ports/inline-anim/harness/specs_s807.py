"""specs_s807.py - animation layer thread, batch 807: ZTARGET/ZIKHAND Save/Load, ZIKHAND::AttachItem.
Save/load streams are fake objects whose slots log what they get (pointed-to data by content, since some pointers
are stack locals) and, for loads, write data derived from a per-case counter."""
import struct
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot, install_logger


def _is_heap(p):
    return 0x20000000 <= p < 0x30000000


def _saver(c):
    e = c.emu

    def val(name):
        def h(e, r):
            e.calllog.append((name, e.arg32(0)))
            e.ret(eax=0, argbytes=4)
        return h

    def ptr(name, n):
        def h(e, r):
            p = e.arg32(0)
            e.calllog.append((name, _is_heap(p), e.rbytes(p, 4 * n)))
            e.ret(eax=0, argbytes=4)
        return h

    def blk(e, r):
        p, n = e.arg32(0), e.arg32(1)
        e.calllog.append(('save.block', _is_heap(p), n, e.rbytes(p, n)))
        e.ret(eax=0, argbytes=8)
    return vt_object(c, 0x10, {0x60: val('save.byte'), 0x70: ptr('save.mat', 9), 0x68: ptr('save.vec', 3),
                               0x4c: val('save.float'), 0x3c: val('save.dword'), 0x10: blk}, name='save')


def _loader(c):
    e, r = c.emu, c.rng
    cnt = [r.getrandbits(16)]

    def fill(p, n):
        for i in range(n):
            cnt[0] = (cnt[0] * 1103515245 + 12345) & 0xffffffff
            e.w8(p + i, cnt[0] >> 16)

    def ptr(name, n):
        def h(e, r):
            p = e.arg32(0)
            e.calllog.append((name, _is_heap(p)))
            fill(p, n)
            e.ret(eax=0, argbytes=4)
        return h

    def blk(e, r):
        p, n = e.arg32(0), e.arg32(1)
        e.calllog.append(('load.block', _is_heap(p), n))
        fill(p, n)
        e.ret(eax=0, argbytes=8)
    return vt_object(c, 0x10, {0x68: ptr('load.byte', 1), 0x74: ptr('load.mat', 36), 0x6c: ptr('load.vec', 12),
                               0x50: ptr('load.float', 4), 0x40: ptr('load.dword', 4), 0x18: blk}, name='load')


def _obj(c):
    e = c.emu

    def cb2id(e, r):
        w = tuple(e.arg32(k) for k in range(4))
        e.calllog.append(('obj.CallBackToId', w))
        e.ret(eax=(w[0] ^ w[1] * 3) & 0xffffffff, argbytes=16)

    def id2cb(e, r):
        p, i = e.arg32(0), e.arg32(1)
        e.calllog.append(('obj.IdToCallBack', _is_heap(p), i))
        for k in range(4):
            e.w32(p + 4 * k, (i * (k + 7)) & 0xffffffff)
        e.ret(eax=p, argbytes=8)
    return vt_object(c, 0x40, {0x3bc: cb2id, 0x3c0: id2cb}, name='obj')


def _tgt(c):
    t = rnd(c, 0x60)
    if c.rng.random() < 0.3:
        c.emu.w32(t + 0x3d, 0)
    return t


def _tsave(c):
    only_hooks(c, {})
    return [_tgt(c), _saver(c), _obj(c)]


def _tload(c):
    only_hooks(c, {})
    return [_tgt(c), _loader(c), _obj(c)]


def _hsave(c):
    only_hooks(c, {})
    return [rnd(c, 0x80), _saver(c), _obj(c)]


def _hload(c):
    only_hooks(c, {})
    return [rnd(c, 0x80), _loader(c), _obj(c)]


def _attach(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x4dcbb0: logged_fn('SetOwnerDraw', 1),
                   0x474eb0: logged_fn('PlaceItem', 2)})
    install_logger(c, nargs=2)   # after only_hooks: only_hooks restores the logger global
    self = rnd(c, 0x80)
    cur = r.choice([0, r.randint(1, 5)])
    e.w32(self + 0x51, cur)
    e.w32(self + 0x56, r.choice([0x11, 0x11, 3, 7, r.getrandbits(32)]))
    items = {}
    for i in range(0, 6):
        if r.random() < 0.7:
            it = rnd(c, 0x20)
            e.w32(it + 8, r.getrandbits(32))
            vt = e.fake_vtable('item%d' % i, 0xbd, {0x2f0: vslot('item.2f0', 1)})
            e.w32(it, vt)
            items[i] = it
    sc = vt_object(c, 0xb00, {0x58: vslot('scene.GetItem', 1, ret=lambda e, a: items.get(a[0], 0)),
                              0x4c: vslot('scene.4c', 3, ret=0x99)}, name='scene')

    def att(e, res):
        g, b, z, p = (e.arg32(k) for k in range(4))
        off = tuple(struct.unpack('<3I', e.rbytes(p, 12))) if p else None
        e.calllog.append(('obj.AttachGeomToBone', g, b, z, off))
        e.ret(eax=0, argbytes=16)
    obj = vt_object(c, 0x40, {0x290: att, 0x294: vslot('obj.Detach', 2), 0x128: vslot('obj.128', 3)}, name='obj')
    g = rnd(c, 0xa0)
    e.w32(g + 0x9b, sc)
    e.w32(0x70039c, g)
    nid = r.choice([0, cur, r.randint(1, 5), r.randint(1, 5), r.getrandbits(32)])
    return [self, obj, nid]


S(0x467850, 'ZTARGET::Save', 'thiscall', None, ret='al', gen=_tsave, note='batch807')
S(0x466eb0, 'ZTARGET::Load', 'thiscall', None, ret='al', gen=_tload, note='batch807')
S(0x475380, 'ZIKHAND::Save', 'thiscall', None, ret='al', gen=_hsave, note='batch807')
S(0x474730, 'ZIKHAND::Load', 'thiscall', None, ret='al', gen=_hload, note='batch807')
S(0x472280, 'ZIKHAND::AttachItem', 'thiscall', None, ret='eax', gen=_attach, note='batch807')
