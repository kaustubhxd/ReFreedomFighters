"""specs_s235.py - ladder thread batch 235: ZIKLNKOBJ::EmitFootDustParticle base body (0x4664a0)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from pe_emu import f32
import ladder_kit as K


def _ed(c):
    e, r = c.emu, c.rng
    if 0x4664a0 in e.hooks:      # batch 231 hooks this address as a stand-in; this spec runs the real base body
        e.unhook(0x4664a0)
    eng = K.engine(c)
    gobj = K.rnd(c, 0xc00)
    e.w32(0x7003b8, gobj)
    e.w8(gobj + 0xab8, 0 if r.random() < 0.85 else 1)
    owner = K.rnd(c, 0x80)
    e.w32(owner + 0x3c, r.getrandbits(32) if r.random() < 0.6 else (r.getrandbits(32) | 0x1000))
    spd = K.rnd(c, 0x400)
    e.wf32(spd + 0x271, f32(r.choice([0.0, 100.0, 2000.0, 2001.0, r.uniform(0, 3000)])))
    s = K.rnd(c, 0x200)
    e.w32(s + 8, owner)
    e.w32(s + 0x6c, spd)
    tkey = r.getrandbits(32)
    e.w32(s + 0x15d, tkey)
    ka, kb = r.getrandbits(32), r.getrandbits(32)
    tmpl = K.rnd(c, 0x20)
    emit = K.rnd(c, 0x40)
    d = K.rnd(c, 0x100)
    e.w32(eng + 0x9b, d)

    def dbl(e2, a):
        k = a[0]
        return (tmpl if k == tkey else emit), None, None
    e.w32(d, K.vt(c, 'database', {0x58: (1, dbl)}, nslots=0x60))

    def gc(e2, a):
        e2.calllog.append(('GetController', e2.reg('ecx')))
        e2.w32(a[0] if False else e2.arg32(0), ka)
        e2.w32(e2.arg32(1), kb)
        e2.ret(argbytes=8)
    e.hook(0x456b70, gc)

    def spawn(e2, a):
        return 0, None, (tuple(a[0:1]), K.bits3(e2, a[1]), K.bits3(e2, a[2]), a[3] if len(a) > 3 else None)
    e.w32(emit, K.vt(c, 'emitter', {0x218: (4, lambda e2, a: (0, None, (a[0], K.bits3(e2, a[1]), K.bits3(e2, a[2]), a[3])))}, nslots=0x230))

    def b3(e2, a):
        vals = [c.fv(-300.0, 300.0) for _ in range(3)]
        K.wv3(e2, a[0], vals)
        return r.getrandbits(32), None, None
    e.w32(s, K.vt(c, 'self', {0x3b8: (1, b3), 0x398: (1, lambda e2, a: (0, None, None)),
                              0x84: (1, lambda e2, a: (0, None, K.bits3(e2, a[0])))}, nslots=0x400))
    rnd = [f32(r.uniform(0, 1)) for _ in range(2)]
    st = {'i': 0}

    def rf(e2, a):
        v = rnd[st['i'] % 2]
        st['i'] += 1
        return 0, v, None
    e.w32(eng, K.vt(c, 'engine', {0x1c0: (2, rf)}, nslots=0x80))
    return [s, F(c.fv(-1.0, 4096.0))]


S(0x4664a0, 'ZIKLNKOBJ::EmitFootDustParticle (base)', 'thiscall', None, ret=None, gen=_ed, note='batch235')
