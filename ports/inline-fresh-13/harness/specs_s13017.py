"""specs_s13017.py - fresh-13 batch 17: 0x4f7b10 ZSlider::ClassInit. Thiscall, no args.
ZCONTROL::ClassInit 0x4f9bc0 logged. List 1 (+0x50) and list 2 (+0x54, GetPrev 0x4db520 hooked by a node map) of 0..4
children; child objects have type flags (+0xc -> +0x23) with 0x100000 set or not (or no object), vtbl[+0x1e0] random
bool, byte +0x21 0x80 or not, and a geom at +8. GetSize 0x4db7c0 / GetPos 0x4db500 write per-geom floats into the
out vector (custom hooks: they log the geom, never the stack pointer). db slot 0x4c returns a per-object id, slot
0x58 maps ids back (a button geom). Slots 0x258 (scale vector logged by value) / 0x70 (position by value), sender
slot 0x34c (5 args), this-> 0x2c4 / 0x364 / 0x36c, logger 0x700390 slot 0x20 and its cdecl slot 0x2c logged.
+0xa3 is 0 / -0 / NaN / random; +0xab / +0xaf start random or 0; +4 name or 0."""
import struct
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=40, width=7)

    def _code(fn):
        a = c.emu.alloc(16, 16)
        c.emu.wbytes(a, b'\xc3' * 16)
        HOOKED.add(a)
        c.emu.hook(a, fn)
        return a
    geomf = {}

    def geom():
        g = rnd(c, 0x10)
        geomf[g] = ([r.choice([r.uniform(-50, 50), r.uniform(0.5, 40), 0.0]) for _ in range(3)],
                    [r.uniform(-100, 100) for _ in range(3)])
        return g

    def _vec(which, tag):
        def h(e, rr):
            g = e.reg('ecx')
            p = e.r32(e.reg('esp') + 4)
            v = geomf.get(g, ([1.0, 2.0, 3.0], [4.0, 5.0, 6.0]))[which]
            e.wbytes(p, struct.pack('<3f', *v))
            log.put(e, [tag, g])
            e.ret(eax=0, argbytes=4)
        return h
    loghook(c, log, 0x4f9bc0, 0, 1)
    c.emu.hook(0x4db7c0, _vec(0, 2))
    HOOKED.add(0x4db7c0)
    c.emu.hook(0x4db500, _vec(1, 3))
    HOOKED.add(0x4db500)
    bools = [r.choice([0, 1, 1, 0x100, 0x201]) for _ in range(8)]
    cb = {'b': 0}

    def _b(e):
        v = bools[cb['b'] % 8]
        cb['b'] += 1
        return v
    s1e0 = logstub(c, log, 1, 4, ret=_b)
    s258 = logstub(c, log, 2, 5, deref={0: 2})
    s70 = logstub(c, log, 1, 6, deref={0: 3})
    ids = {}

    def child():
        if r.random() < 0.1:
            return 0
        o = vobj(c, 0x30, {0x1e0: s1e0, 0x258: s258, 0x70: s70})
        t = rnd(c, 0x30)
        c.emu.w32(t + 0x23, r.getrandbits(32) & ~0x100000 | r.choice([0, 0x100000, 0x100000]))
        c.emu.w32(o + 0xc, t)
        c.emu.w8(o + 0x21, r.choice([0x80, 0x80, 0x80, 0x7f, 0, 0x81, 0xff]))
        c.emu.w32(o + 8, geom())
        ids[o] = r.getrandbits(32) | 1
        return o
    # list 1: flags mostly with 0x100000 (the button list); list 2: mostly without
    me = vobj(c, 0xc0, {})
    q = 0
    for k in range(r.choice([0, 1, 2, 3, 4])):
        node = rnd(c, 0x64)
        o = child()
        if o and r.random() < 0.8:
            t = c.emu.r32(o + 0xc)
            c.emu.w32(t + 0x23, c.emu.r32(t + 0x23) | 0x100000)
        c.emu.w32(node + 0x54, o)
        c.emu.w32(node + 0x60, q)
        q = node
    c.emu.w32(me + 0x50, q)
    prev = {}
    q = 0
    for k in range(r.choice([0, 1, 2, 3, 4])):
        node = rnd(c, 0x64)
        o = child()
        if o and r.random() < 0.8:
            t = c.emu.r32(o + 0xc)
            c.emu.w32(t + 0x23, c.emu.r32(t + 0x23) & ~0x100000)
        c.emu.w32(node + 0x54, o)
        prev[node] = q
        q = node
    c.emu.w32(me + 0x54, q)
    loghook(c, log, 0x4db520, 0, 7, ret=lambda e: prev.get(e.reg('ecx'), 0))
    byid = {v: k for k, v in ids.items()}
    db = vobj(c, 0x60, {0x4c: logstub(c, log, 1, 8, ret=lambda e: ids.get(e.r32(e.reg('esp') + 4), 0x1234)),
                        0x58: logstub(c, log, 1, 9, ret=lambda e: byid.get(e.r32(e.reg('esp') + 4), 0) or me)})
    c.emu.w32(me + 8, geom())
    sysobj = c.emu.alloc(0xa0, 4)
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(0x70039c, sysobj)
    sender = vobj(c, 0x10, {0x34c: logstub(c, log, 5, 10)})
    vt = c.emu.alloc(0x370, 4)
    c.emu.w32(vt + 0x2c4, logstub(c, log, 0, 11, ret=sender))
    c.emu.w32(vt + 0x364, logstub(c, log, 1, 12))
    c.emu.w32(vt + 0x36c, logstub(c, log, 2, 13))
    c.emu.w32(me, vt)
    lgo = vobj(c, 0x30, {0x2c: logstub(c, log, 3, 14, this=False, pop=False)})
    lg = vobj(c, 0x30, {0x20: logstub(c, log, 2, 15, ret=lgo)})
    c.emu.w32(0x700390, lg)
    c.emu.w32(me + 4, r.choice([0, r.getrandbits(32)]))
    c.emu.w32(me + 0xa3, r.choice([0, 0, 0x80000000, 0x7fc00000,
                                   struct.unpack('<I', struct.pack('<f', r.uniform(-20, 80)))[0]]))
    c.emu.w32(me + 0xab, r.choice([0, r.getrandbits(32)]))
    c.emu.w32(me + 0xaf, r.choice([0, r.getrandbits(32)]))
    flush(c)
    return [me]


S(0x4f7b10, 'ZSlider::ClassInit', 'thiscall', None, ret=None, gen=_gen,
  note='fresh13 batch13017; ZBaseGeom size / pos hooks write per-geom vectors; all slots logged')
