"""specs_s231.py - ladder thread batch 231: ZFFHERO::EmitFootDustParticle (slot 0x400)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from pe_emu import f32
import ladder_kit as K


def _fd(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x500)
    e.w32(s + 0x417, r.getrandbits(32) & (0xffffffff if r.random() < 0.85 else 0xf3ffffff))
    off = [f32(r.uniform(-300, 300)) for _ in range(3)]

    def w(e2, a):
        before = K.bits3(e2, a[0])
        K.wv3(e2, a[0], [f32(x + y) for x, y in zip(K.rv3(e2, a[0]), off)])
        return 0, None, before
    e.w32(s, K.vt(c, 'hero', {0x84: (1, w)}, nslots=0x140))
    eng = K.engine(c)
    rv = [f32(r.uniform(0, 1)) for _ in range(2)]
    st = {'i': 0}

    def rnd(e2, a):
        v = rv[st['i'] % 2]
        st['i'] += 1
        return 0, v, None
    e.w32(eng, K.vt(c, 'engine', {0x1c0: (2, rnd)}, nslots=0x80))
    em = K.rnd(c, 0x40)
    ci = K.rnd(c, 0x40)
    e.w32(em + 0xc, ci)
    if r.random() < 0.9:
        e.w32(ci + 0x23, e.r32(ci + 0x23) | 0x100000)
    e.w32(em, K.vt(c, 'emitter', {0x1bc: (7, lambda e2, a: (0, None, (tuple(e2.r32(a[1] + 4 * i) for i in range(9)), K.bits3(e2, a[2]))))}, nslots=0x80))
    res = K.rnd(c, 0x20)
    d = K.rnd(c, 0x100)
    e.w32(eng + 0x9b, d)
    resp = res if r.random() < 0.9 else 0
    emp = em if r.random() < 0.9 else 0
    e.w32(d, K.vt(c, 'database', {0x160: (1, lambda e2, a: (resp, None, None)), 0x58: (1, lambda e2, a: (emp, None, None))}, nslots=0x60))
    hit = K.rnd(c, 0x60)
    rot = K.rnd(c, 0x10)
    e.w32(rot, K.vt(c, 'hitrot', {0x88: (1, lambda e2, a: (0, None, K.bits3(e2, a[0])))}, nslots=0x30))
    e.w32(hit + 0x54, rot)
    okv = r.getrandbits(32) & (0xffffff00 if r.random() < 0.2 else 0xffffffff)
    vals = [c.fv(-200.0, 200.0) for _ in range(17)]

    def ray(e2, a):
        coli = a[0]
        for i in range(1, 18):
            e2.wf32(coli + 4 * i, vals[i - 1])
        e2.w32(coli + 0x10, hit)
        return okv, None, (K.bits3(e2, a[2]), K.bits3(e2, a[3])) + tuple(x for x in a[4:])
    cm = K.rnd(c, 0x10)
    e.w32(cm, K.vt(c, 'collision', {0x30: (8, ray)}, nslots=0x20))
    cmh = K.rnd(c, 0x40)
    e.w32(cmh + 0x1c, cm)
    e.w32(eng + 0x1aa3, cmh)
    room = K.rnd(c, 0x10)
    e.w32(room, K.vt(c, 'room', {0x94: (2, lambda e2, a: (0, None, None))}, nslots=0x40))
    rp = room if r.random() < 0.9 else 0

    def gor(e2, res_):
        e2.calllog.append(('GetOwnerRoom', e2.reg('ecx')))
        e2.ret(eax=rp)
    e.hook(0x4db3b0, gor)
    def base(e2, res_):
        # stand-in for ZIKLNKOBJ::EmitFootDustParticle (0x4664a0, not lifted): log this and the float bits
        e2.calllog.append(('ZIKLNKOBJ::EmitFootDustParticle', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)
    e.hook(0x4664a0, base)
    if r.random() < 0.5:
        def ah(e2, res_):
            e2.calllog.append(('assert',))
            e2.ret()
        e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [s, F(c.fv())]


S(0x591480, 'ZFFHERO::EmitFootDustParticle', 'thiscall', None, ret=None, gen=_fd, note='batch231')
