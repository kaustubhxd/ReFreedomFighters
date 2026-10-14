"""specs_s877.py - area 50, batch 877: 0x49f010 CMsgForwardToActors::Init (GUESS-free name from the residue file), thiscall, two stack
args (ret 8). The DBREAD readers (0x4e5e40 unsigned short, 0x4e5e80 float in st0) are recorded hooks that answer from a generation-time
list (the reads happen in the exe's order). The render manager's object (eng+0x9b, +0xadc) answers its vt +0x25c (logged); the
logger (0x700390) and its sink are fake and logged. The flag byte at +4 is generated with and without bit 1."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    seq16 = [r.getrandbits(16) for _ in range(8)]
    seqf = [r.uniform(-4, 4) for _ in range(4)]
    st = {'u': 0, 'f': 0}
    ret25c = r.choice([0, 0, r.getrandbits(32) | 1])

    def h16(e, rr):
        v = seq16[st['u'] % len(seq16)]
        st['u'] += 1
        e.calllog.append(('db.u16', v))
        e.ret(eax=v, argbytes=0)

    def hf(e, rr):
        v = seqf[st['f'] % len(seqf)]
        st['f'] += 1
        e.calllog.append(('db.float',))
        e.ret(eax=0, argbytes=0, st0=v)

    def v25c(e, rr):
        e.calllog.append(('mgr.25c', e.arg32(0), e.arg32(1)))
        e.ret(eax=ret25c, argbytes=8)

    def l20(e, rr):
        e.calllog.append(('log.20', e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)

    def s2c(e, rr):
        e.calllog.append(('sink.2c', e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x4e5e40: h16, 0x4e5e80: hf})
    sink = e.fake_object('sink', 0x10, nslots=0x20, slots={0x2c: s2c})
    logger = e.fake_object('logger', 0x10, nslots=9, slots={0x20: l20})
    e.w32(0x700390, logger)
    mgrobj = vt_object(c, 0x1000, {0x25c: v25c}, nslots=0x100, name='rm_obj')
    mgr = rnd(c, 0x1000)
    e.w32(mgr + 0xadc, mgrobj)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    self = rnd(c, 0x100)
    e.w8(self + 4, r.getrandbits(8) if r.random() < 0.5 else (r.getrandbits(8) | 2))
    geom = rnd(c, 0x40)
    db = rnd(c, 0x40)
    return [self, geom, db]


S(0x49f010, 'CMsgForwardToActors::Init (DBREAD reader)', 'thiscall', None, gen=_gen, note='area50 batch877')
