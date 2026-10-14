"""specs_s806.py - animation layer thread, batch 806: ZIKHAND. Stack buffers handed to stubs are logged by
content (their addresses differ between the original and the port)."""
import struct
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _gettype(c):
    only_hooks(c, {})
    r = c.rng
    tm = 0 if r.random() < 0.2 else vt_object(c, 0x20, {0x300: vslot('tmpl.300', 0, ret=r.getrandbits(32))})
    it = 0 if r.random() < 0.2 else vt_object(c, 0x20, {0x2e8: vslot('item.2e8', 0, ret=tm)})
    return [vt_object(c, 0x80, {0x10: vslot('hand.GetItem', 0, ret=it)}, name='hand')]


def _reset(c):
    only_hooks(c, {})
    return [rnd(c, 0x80)]


def _slip(c):
    only_hooks(c, {})
    r = c.rng
    it = r.choice([0, r.getrandbits(32)])
    return [vt_object(c, 0x80, {0x10: vslot('hand.GetItem', 0, ret=it), 8: vslot('hand.vt8', 2)}, name='hand'),
            r.getrandbits(32)]


def _settarget(c):
    r = c.rng
    hooks = {0x4658d0: logged_fn('CallBackAndRemove', 1), 0x467aa0: logged_fn('SetMatPosGeom', 3),
             0x4678e0: logged_fn('SetCallBack', 4), 0x467b00: logged_fn('SetTime', 2),
             0x466600: logged_fn('Enable', 1, ret=r.getrandbits(32))}
    only_hooks(c, hooks)
    return [rnd(c, 0x80), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), F(c.fv(0, 2))] + \
        [r.getrandbits(32) for _ in range(4)]


def _content(e, a, n):
    return tuple(struct.unpack('<%dI' % n, e.rbytes(a, 4 * n)))


def _place(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    seed = r.getrandbits(32)

    def bone(e, res):
        b, m, p = e.arg32(0), e.arg32(1), e.arg32(2)
        rr = __import__('random').Random(seed ^ b)
        for i in range(9):
            e.wf32(m + 4 * i, rr.uniform(-1, 1))
        for i in range(3):
            e.wf32(p + 4 * i, rr.uniform(-50, 50))
        e.calllog.append(('obj.BoneMatPos', b))
        e.ret(eax=b * 3 + 1, argbytes=12)

    def mp(name, change):
        def h(e, res):
            m, p = e.arg32(0), e.arg32(1)
            e.calllog.append((name, e.reg('ecx'), _content(e, m, 9), _content(e, p, 3)))
            if change:
                for i in range(3):
                    e.wf32(p + 4 * i, e.rf32(p + 4 * i) + change)
                e.wf32(m, e.rf32(m) * 0.5)
            e.ret(eax=0, argbytes=8)
        return h
    obj = vt_object(c, 0x40, {0x2b4: bone, 0x390: vslot('obj.390', 1), 0x98: mp('obj.ToWorld', 3.0)}, name='obj')
    g = vt_object(c, 0x20, {0x94: mp('geom.94', -1.5)}, name='geom')
    item = vt_object(c, 0x40, {0x20: vslot('item.Geom', 0, ret=g), 0x2d4: mp('item.SetMatPos', 0)}, name='item')
    hand = rnd(c, 0x80)
    for i in range(3):
        e.wf32(hand + 0x5a + 4 * i, c.fv(-10, 10))
    return [hand, obj, item]


S(0x474410, 'ZIKHAND::GetItemType', 'thiscall', None, ret='eax', gen=_gettype, note='batch806')
S(0x4752e0, 'ZIKHAND::Reset', 'thiscall', None, gen=_reset, note='batch806; ZTARGET::Clear runs as exe code')
S(0x475a80, 'ZIKHAND::SlipItem', 'thiscall', None, gen=_slip, note='batch806')
S(0x475a20, 'ZIKHAND::SetTarget', 'thiscall', None, gen=_settarget, note='batch806; ZTARGET calls hooked')
S(0x474eb0, 'ZIKHAND::PlaceItem', 'thiscall', None, gen=_place, note='batch806')
