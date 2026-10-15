"""specs_s242.py - ladder thread batch 242: ZFFHERO::OnMoveNotifyLargeObj (fast-mover knockback)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _omn(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    e.wf32(eng + 0x48, f32(r.choice([1.0 / 60.0, 1.0 / 25.0, 0.0, r.uniform(0.01, 0.1)])))
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    e.w32(d, K.vt(c, 'database', {0x4c: (2, lambda e2, a: (K.rnd(c, 0x40) if r.random() < 0.9 else 0, None, None))}, nslots=0x60))
    hero = K.rnd(c, 0x900)
    e.wf32(hero + 0x7ff, f32(r.choice([2.0, 4.99, 5.0, 10.0, r.uniform(0, 20)])))
    e.w32(hero, K.vt(c, 'hero', {0x5bc: (3, lambda e2, a: (0, None, (K.bits3(e2, a[0]), K.bits3(e2, a[1]), a[2])))}, nslots=0x800))

    def ahp(e2, res):
        e2.calllog.append(('AdjustHitPoints', e2.reg('ecx'), tuple(e2.arg32(i) for i in range(3))))
        e2.ret(argbytes=12)
    e.hook(0x58b9c0, ahp)
    m = K.rnd(c, 0x100)
    e.wf32(m + 5, f32(r.choice([40.0, 50.0, 51.0, 300.0, 1000.0, r.uniform(0, 2000)])))
    e.w32(m + 1, r.getrandbits(32))
    for off in (0x39, 0x69):
        for i in range(3):
            e.wf32(m + off + 4 * i, c.fv(-300.0, 300.0))
    return [hero, m]


S(0x5935a0, 'ZFFHERO::OnMoveNotifyLargeObj', 'thiscall', None, ret=None, gen=_omn, note='batch242')
