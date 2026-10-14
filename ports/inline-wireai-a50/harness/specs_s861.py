"""specs_s861.py - area 50, batch 861: 0x513190 (name GUESS), thiscall, no args, no result.
The render manager (engine +0x9b): vt +0x138 gives a settings object; its vt +0x88 writes an id for a name; vt +0x58 maps the
id to an object, whose vt +0x100 (name) gives a value; the id may be 0 (then the debug line with the default string runs).
The logger (0x700390, vt +0x20) and its sink (vt +0x2c, cdecl) are fake and log the name argument. The sound manager (engine
+0x1a9f, vt +0x60) is present in most cases. All the names are generation-time choices, so both runs see the same values."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    id1 = r.choice([0, r.getrandbits(32) | 1])
    id2 = r.choice([0, r.getrandbits(32) | 1])
    tv = r.getrandbits(32)

    def v88(e, rr):
        name, out = e.arg32(0), e.arg32(1)
        val = id1 if name == 0x692dec else id2
        e.w32(out, val)
        e.calllog.append(('set.88', name))
        e.ret(eax=0, argbytes=8)

    def m138(e, rr):
        e.calllog.append(('mgr.138',))
        e.ret(eax=X, argbytes=0)

    def m58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('mgr.58', k))
        e.ret(eax=O if k else 0, argbytes=4)

    def v100(e, rr):
        e.calllog.append(('obj.100', e.arg32(0)))
        e.ret(eax=tv, argbytes=4)

    def v60(e, rr):
        e.calllog.append(('snd.60', e.arg32(0), e.arg32(1)))
        e.ret(eax=tv ^ 0x55, argbytes=8)

    def logger20(e, rr):
        e.calllog.append(('log.20', e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)

    def sink2c(e, rr):
        e.calllog.append(('sink.2c', e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {})
    X = vt_object(c, 0x40, {0x88: v88}, nslots=0x100, name='settings')
    mgr = vt_object(c, 0x40, {0x138: m138, 0x58: m58}, nslots=0x140, name='render')
    O = vt_object(c, 0x40, {0x100: v100}, nslots=0x110, name='obj')
    snd = vt_object(c, 0x40, {0x60: v60}, nslots=0x70, name='snd')
    sink = e.fake_object('sink', 0x10, nslots=0x20, slots={0x2c: sink2c})
    logger = e.fake_object('logger', 0x10, nslots=9, slots={0x20: logger20})
    e.w32(0x700390, logger)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(g + 0x1a9f, snd if r.random() < 0.8 else 0)
    e.w32(0x70039c, g)
    self = rnd(c, 0x300)
    e.w32(self + 4, r.choice([0, rnd(c, 16)]))
    e.w32(self + 0x12f, r.choice([0, 1, r.getrandbits(32)]))
    return [self]


S(0x513190, 'Init513190 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch861')
