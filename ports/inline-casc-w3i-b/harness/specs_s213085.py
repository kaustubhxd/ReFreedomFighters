"""specs_s213085.py - batch 213085: panel idle layout through many widget slots, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5743c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    rb = lambda emu, k: r.choice([0, 0, 1, 0x100, 0xff, r.getrandbits(32)])

    def widget(slots=None):
        s = {0xbc: sl(1)}
        s.update(slots or {})
        return obj(c, 0x20, s, nslots=0x100)
    X = obj(c, 0x20, {0xdc: sl(0, rb)}, nslots=0x60)
    G = obj(c, 0x100, {0xbc: sl(0, X)}, nslots=0x60)
    Y = obj(c, 0x20, {0x254: sl(0), 0x250: sl(0)}, nslots=0x100)
    T = obj(c, 0x20, {0x58: sl(1, Y)}, nslots=0x60)
    e.w32(G + 0x9b, T)
    e.wbytes(G + 0x73, struct.pack('<I', r.choice([0, 480, 1000, 0x28, 0x7fffffff, 0x80000000, r.getrandbits(32), r.randint(0, 2000)])))
    e.w32(0x70039c, G)
    R = widget()
    Z = obj(c, 0x20, {0x25c: sl(2, R)}, nslots=0x100)
    this = obj(c, 0x200, {0xec: sl(0), 0x84: sl(0, Z), 0xd4: sl(1)}, nslots=0x100)
    F = obj(c, 0x8e0, {0x214: sl(1)}, nslots=0x100)
    e.w32(this + 0xf8, F)
    e.w32(this + 0x4c, widget())
    e.w32(this + 0x50, widget())
    e.w32(this + 0x180, 0 if r.random() < 0.25 else widget({0x284: sl(1)}))
    e.w32(this + 0x184, 0 if r.random() < 0.25 else widget({0x284: sl(1)}))
    e.w32(this + 0x1b0, r.choice([0, 0x1234, r.getrandbits(32)]))
    e.w32(this + 0x1b4, r.choice([0, 0x5678, r.getrandbits(32)]))
    e.w32(this + 0x1c8, 0 if r.random() < 0.3 else widget())
    o90 = rnd(c, 0x700)
    e.w32(this + 0x90, o90)
    e.w32(this + 0x1c4, r.getrandbits(32))
    e.w32(this + 0x1bc, r.getrandbits(32))
    e.w32(this + 0x1c0, r.getrandbits(32))
    e.w32(this + 0x1dc, widget({0x70: sl(1, deref={0: 3})}))
    e.w32(this + 0xdc, r.getrandbits(32))
    e.wbytes(this + 0x1f1, bytes([r.choice([0, 1])]))
    e.wbytes(F + 0x8cf, bytes([r.choice([0, 1])]))
    hook_rec(c, 0x563110, 2, this=True)
    hook_rec(c, 0x5747e0, 0, this=True)
    hook_rec(c, 0x5aa6e0, 0, this=True)
    hook_rec(c, 0x561720, 2, this=True)
    hook_rec(c, 0x573d40, 0, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, r.getrandbits(32), r.getrandbits(32)]


S(0x5743c0, 'panel_idle_layout', 'thiscall', None, ret='al', gen=g5743c0)
