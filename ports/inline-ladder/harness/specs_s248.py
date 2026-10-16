"""specs_s248.py - ladder thread batch 248: ZFFHERO::GetAttachedGeomMatPos (base fallback or member/database path)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _gamp(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    member = K.rnd(c, 0x40)
    e.w32(eng + 0x190f, member)
    x = r.getrandbits(32)
    e.w32(member, K.vt(c, 'member', {0xb4: (1, lambda e2, a: (x, None, (K.nostack(a[0]),)))}, nslots=0x100))
    obj = K.rnd(c, 0x40)
    e.w32(obj, K.vt(c, 'obj', {0x80: (2, lambda e2, a: (0, None, (K.nostack(a[0]), K.nostack(a[1]))))}, nslots=0x100))
    e.w32(d, K.vt(c, 'database', {0x58: (1, lambda e2, a: (obj, None, (a[0],)))}, nslots=0x100))
    hero = K.rnd(c, 0x900)
    e.w8(hero + 0x67f, r.choice([0, 0, 1, 2, 0x80]))
    e.w32(hero, K.vt(c, 'hero', {0x94: (2, lambda e2, a: (0, None, (K.nostack(a[0]), K.nostack(a[1]))))}, nslots=0x100))

    def base(e2, res):
        e2.calllog.append(('ZLNKOBJ::GetAttachedGeomMatPos', K.nostack(e2.reg('ecx')), tuple(K.nostack(e2.arg32(i)) for i in range(3))))
        e2.ret(eax=r.choice([0, 1]), argbytes=12)
    e.hook(0x462d10, base)
    g = K.rnd(c, 16)
    mat = K.rnd(c, 0x40)
    pos = K.rnd(c, 0x20)
    return [hero, g, mat, pos]


S(0x591980, 'ZFFHERO::GetAttachedGeomMatPos', 'thiscall', None, ret='al', gen=_gamp, note='batch248')
