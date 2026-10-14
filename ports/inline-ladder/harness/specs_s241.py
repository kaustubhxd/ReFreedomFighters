"""specs_s241.py - ladder thread batch 241: ZFFHERO::SendInventoryFull (throttled OSD message)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _sif(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    now = r.randint(0, 1 << 22)
    e.w32(eng + 0x40, now)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    tab = K.rnd(c, 0x20)
    e.w32(tab, K.vt(c, 'text', {0: (2, lambda e2, a: (e2.cstr('Inventory full'), None, None))}, nslots=4))
    e.w32(d + 0xae4, tab)
    e.w32(d, K.vt(c, 'database', {}, nslots=0x60))
    hero = K.rnd(c, 0xa00)
    item = r.choice([0, r.getrandbits(32), 0x1234])
    e.w32(hero + 0x953, item if r.random() < 0.5 else r.getrandbits(32))
    tval = f32(now / 1024.0) if r.random() < 0.3 else f32(r.uniform(0, (now + 4000) / 1024.0))
    e.wf32(hero + 0x957, tval)
    osd = K.rnd(c, 0x40) if r.random() < 0.8 else 0
    e.w32(hero + 0x852, osd)

    def ma(e2, a):
        e2.calllog.append(('MessageAdd', e2.reg('ecx'), tuple(e2.arg32(i) for i in range(3))))
        e2.ret(argbytes=12)
    e.hook(0x59a580, ma)
    return [hero, item]


S(0x594e30, 'ZFFHERO::SendInventoryFull', 'thiscall', None, ret=None, gen=_sif, note='batch241')
