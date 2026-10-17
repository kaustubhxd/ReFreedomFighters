"""specs_s810.py - animation layer thread, batch 810: StartMatBoneMotion, ActivateAnimSegment."""
import math
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _gfpq(c):
    def h(e, r):
        aid, flag, pos, quat, fr = (e.arg32(k) for k in range(5))
        e.calllog.append(('GetFramePosQuat', aid, flag, pos, fr))
        rr = __import__('random').Random(aid * 31 + fr)
        v = [rr.gauss(0, 1) for _ in range(4)]
        n = math.sqrt(sum(x * x for x in v))
        for i in range(4):
            e.wf32(quat + 4 * i, v[i] / n)
        for i in range(3):
            e.wf32(pos + 4 * i, rr.uniform(-5, 5))
        e.ret(eax=0, argbytes=0x14)
    return vt_object(c, 0x20, {0xc: h}, name='file')


def _smbm(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    n = r.randint(1, 6)
    tab = rnd(c, 0x18 * n + 0x30)
    for i in range(n):
        e.w8(tab + 0x18 * i + 4, r.choice([0, 1, 2, 3]))
        cur = rnd(c, 0x40)
        e.w32(cur + 0x14, r.choice([0, 0x800, r.getrandbits(32)]))
        e.w32(tab + 0x18 * i + 0x14, cur)
    o = vt_object(c, 0x100, {0x2cc: vslot('vt2cc', 0), 0x340: vslot('EndMatBoneMotion', 2)}, nslots=0xd2, name='lnk')
    e.w32(o + 0x1c, tab)
    e.w32(o + 0x20, n)
    e.w32(o + 0x5c, _gfpq(c))
    ba = rnd(c, 0x80)
    e.w32(ba + 0x14, r.choice([0, 0x400, r.getrandbits(32)]))
    e.w32(ba + 0x10, 0 if r.random() < 0.3 else rnd(c, 0x20))
    e.wf32(ba + 4, r.choice([0.0, 0.0, c.fv(0, 10)]))
    return [o, r.getrandbits(32), r.getrandbits(16), r.choice([0, 0, r.randint(0, n - 1)]), ba]


def _aas(c):
    e, r = c.emu, c.rng
    pool_new = [0]

    def new(e, res):
        sz = e.arg32(0)
        e.calllog.append(('new', sz))
        a = e.alloc(sz, 8)   # never 0: a failed new crashes the original on a null vtable read (UB in C++)
        e.ret(eax=a, argbytes=0)

    def ctor(e, res):
        p, a, b = e.reg('ecx'), e.arg32(0), e.arg32(1)
        e.calllog.append(('LINKREFTAB', p, a, b))
        e.w32(p, pool)
        e.ret(eax=p, argbytes=8)
    r2 = __import__('random').Random(r.getrandbits(32))
    only_hooks(c, {0x41e290: new, 0x4cca60: ctor, 0x462460: logged_fn('ZBoneAnim::Create', 2)})

    def take(e, res):
        f = e.arg32(0)
        e.calllog.append(('pool.take', e.reg('ecx'), f))
        e.ret(eax=e.alloc(0x80, 4) + 4, argbytes=4)
    pool_vt = e.fake_vtable('pool', 9, {4: take, 0x20: vslot('pool.give', 1)})
    pool = pool_vt
    p = rnd(c, 0x10)
    e.w32(p, pool_vt)
    file = vt_object(c, 0x20, {0x20: vslot('file.Next', 1, ret=r.choice([0, 0, r.getrandbits(32)]))}, name='file')
    o = vt_object(c, 0x100, {0x288: vslot('GetAnimDeltaBones', 1, ret=0x7777),
                             0x34c: vslot('vt34c', 2, ret=r.choice([0, 1, 0x100])),
                             0x228: vslot('ActivateAnimSegment', 5)}, nslots=0xe0, name='lnk')
    e.w32(o + 0x18, 0 if r.random() < 0.4 else p)
    e.w32(o + 0x5c, file)
    hdr = 0 if r.random() < 0.1 else r.getrandbits(32)
    return [o, hdr, r.getrandbits(32), F(c.fv()), F(c.fv()), F(c.fv())]


S(0x464bd0, 'ZLNKOBJ::StartMatBoneMotion', 'thiscall', None, ret='al', gen=_smbm, note='batch810')
S(0x461250, 'ZLNKOBJ::ActivateAnimSegment(hdr)', 'thiscall', None, ret='eax', gen=_aas, note='batch810')
